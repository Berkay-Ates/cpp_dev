// #pragma once
// #include <cstddef>
// #include <utility>

// template <typename T>
// class Vector {
//    public:
//     Vector() {
//         // allocate memory for 2 elements
//         ReAlloc(2);
//     }

//     void pushBack(const T& value) {
//         if (m_size >= m_capacity) ReAlloc(m_capacity + m_capacity / 2);

//         m_data[m_size] = value;
//         m_size++;
//     }

//     void pushBack(T&& value) {
//         if (m_size >= m_capacity) ReAlloc(m_capacity + m_capacity / 2);

//         m_data[m_size] = std::move(value);
//         m_size++;
//     }

//     template <typename... Args>
//     T& emplaceBack(Args&&... args) {
//         if (m_size >= m_capacity) ReAlloc(m_capacity + m_capacity / 2);

//         new (&m_data[m_size]) T(std::forward<Args>(args)...);
//         return m_data[m_size++];
//     }

//     void popBack() {
//         if (m_size > 0) {
//             m_size--;
//             m_data[m_size].~T();
//         }
//     }

//     void clear() {
//         for (size_t i = 0; i < m_size; i++) m_data[i].~T();

//         m_size = 0;
//     }

//     const T& operator[](size_t index) const { return m_data[index]; }
//     T& operator[](size_t index) { return m_data[index]; }

//     size_t Size() const { return m_size; }

//     ~Vector() {
//         clear();
//         ::operator delete(m_data, m_capacity * sizeof(T));
//     }

//    private:
//     void ReAlloc(size_t newCapacity) {
//         // 1. allocate new block of memory
//         // 2. copy/move old element into new block
//         // 3. delete

//         T* newBlock = (T*)::operator new(newCapacity * sizeof(T));

//         if (newCapacity < m_size) {
//             m_size = newCapacity;
//         }

//         for (size_t i = 0; i < m_size; i++) newBlock[i] = std::move(m_data[i]);

//         for (size_t i = 0; i < m_size; i++) m_data[i].~T();

//         ::operator delete(m_data, m_capacity * sizeof(T));
//         m_data = newBlock;
//         m_capacity = newCapacity;
//     }

//    private:
//     T* m_data = nullptr;
//     size_t m_size = 0;
//     size_t m_capacity = 0;
// };

#pragma once
#include <cstddef>
#include <utility>

template <typename Vector>
class VectorIterator {
   public:
    using ValueType = typename Vector::ValueType;
    using PointerType = ValueType*;
    using ReferenceType = ValueType&;

   public:
    VectorIterator(PointerType ptr) : m_Ptr(ptr) {}

    VectorIterator& operator++() {
        m_Ptr++;
        return *this;
    }

    VectorIterator operator++(int) {
        VectorIterator iterator = *this;
        ++(*this);
        return iterator;
    }

    VectorIterator& operator--() { m_Ptr--; }
    VectorIterator operator--(int) {
        VectorIterator iterator = *this;
        --(*this);
        return iterator;
    }

    ReferenceType operator[](int index) { return *(m_Ptr + index); }

    PointerType operator->() { return m_Ptr; }

    ReferenceType operator*() { return *m_Ptr; }

    bool operator==(const VectorIterator& other) const { return m_Ptr == other.m_Ptr; }
    bool operator!=(const VectorIterator& other) const { return !(*this == other); }

   private:
    PointerType m_Ptr;
};

template <typename T>
class Vector {
   public:
    using ValueType = T;
    using Iterator = VectorIterator<Vector<T>>;

   public:
    Vector() {
        // allocate memory for 2 elements
        ReAlloc(2);
    }

    // Copy constructor
    Vector(const Vector& other) {
        ReAlloc(other.m_capacity);
        for (size_t i = 0; i < other.m_size; i++) {
            new (&m_data[i]) T(other.m_data[i]);
        }
        m_size = other.m_size;
    }

    // Move constructor
    Vector(Vector&& other) noexcept
        : m_data(other.m_data), m_size(other.m_size), m_capacity(other.m_capacity) {
        other.m_data = nullptr;
        other.m_size = 0;
        other.m_capacity = 0;
    }

    void pushBack(const T& value) {
        if (m_size >= m_capacity) ReAlloc(m_capacity + m_capacity / 2);

        new (&m_data[m_size]) T(value);
        m_size++;
    }

    void pushBack(T&& value) {
        if (m_size >= m_capacity) ReAlloc(m_capacity + m_capacity / 2);

        new (&m_data[m_size]) T(std::move(value));
        m_size++;
    }

    template <typename... Args>
    T& emplaceBack(Args&&... args) {
        if (m_size >= m_capacity) ReAlloc(m_capacity + m_capacity / 2);

        new (&m_data[m_size]) T(std::forward<Args>(args)...);
        return m_data[m_size++];
    }

    void popBack() {
        if (m_size > 0) {
            m_size--;
            m_data[m_size].~T();
        }
    }

    void clear() {
        for (size_t i = 0; i < m_size; i++) m_data[i].~T();

        m_size = 0;
    }

    const T& operator[](size_t index) const { return m_data[index]; }
    T& operator[](size_t index) { return m_data[index]; }

    size_t Size() const { return m_size; }

    Iterator begin() { return Iterator(m_data); }
    Iterator end() { return Iterator(m_data + m_size); }

    // Copy assignment operator
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            clear();
            if (m_capacity < other.m_size) {
                ::operator delete(m_data, m_capacity * sizeof(T));
                m_data = (T*)::operator new(other.m_capacity * sizeof(T));
                m_capacity = other.m_capacity;
            }
            for (size_t i = 0; i < other.m_size; i++) {
                new (&m_data[i]) T(other.m_data[i]);
            }
            m_size = other.m_size;
        }
        return *this;
    }

    // Move assignment operator
    Vector& operator=(Vector&& other) noexcept {
        if (this != &other) {
            clear();
            ::operator delete(m_data, m_capacity * sizeof(T));

            m_data = other.m_data;
            m_size = other.m_size;
            m_capacity = other.m_capacity;

            other.m_data = nullptr;
            other.m_size = 0;
            other.m_capacity = 0;
        }
        return *this;
    }

    ~Vector() {
        clear();
        ::operator delete(m_data, m_capacity * sizeof(T));
    }

   private:
    void ReAlloc(size_t newCapacity) {
        // 1. allocate new block of memory
        T* newBlock = (T*)::operator new(newCapacity * sizeof(T));

        if (newCapacity < m_size) {
            // Call destructors for elements that won't be moved
            for (size_t i = newCapacity; i < m_size; i++) {
                m_data[i].~T();
            }
            m_size = newCapacity;
        }

        // 2. Move old elements to new block using placement new
        for (size_t i = 0; i < m_size; i++) {
            new (&newBlock[i]) T(std::move(m_data[i]));
        }

        // 3. Destroy old elements
        for (size_t i = 0; i < m_size; i++) {
            m_data[i].~T();
        }

        // 4. Free old memory and update pointers
        ::operator delete(m_data, m_capacity * sizeof(T));
        m_data = newBlock;
        m_capacity = newCapacity;
    }

   private:
    T* m_data = nullptr;
    size_t m_size = 0;
    size_t m_capacity = 0;
};