#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

/*
    header is of 4 bytes and maxBytes can be stored as 512 bytes
    header stores the body length that is the current body length
    data stores the header+bodyLength with maximum size of header+maxBytes

    client attempts to send message:- It will encode header and put message into the data and send
   data

   server gets the message, decodes the header, get the bodylength from the header and hence
   complete body then server sends the message to all the clients connected to that room.
*/

class Message {
   public:
    Message() : body_length_(0) {}

    enum { maxBytes = 512 };
    enum { header = 4 };

    Message(std::string message) {
        body_length_ = getNewBodyLength(message.size());
        encodeHeader();
        std::memcpy(data + header, message.c_str(), body_length_);
    }

    void printMessage() {
        std::string message = getData();
        std::cout << "Message Received: " << message << std::endl;
    }

    std::string getData() {
        int length = header + body_length_;
        std::string result(data, length);
        return result;
    }

    std::string getBody() {
        std::string dataStr = getData();
        std::string result = dataStr.substr(header, body_length_);
        return result;
    }

    size_t getNewBodyLength(size_t newLength) {
        if (newLength > maxBytes) {
            return maxBytes;
        }
        return newLength;
    }

    void encodeHeader() {
        char newHeader[header + 1] = "";
        sprintf(newHeader, "%4d", static_cast<int>(body_length_));
        memcpy(data, newHeader, header);
    }

    bool decodeHeader() {
        char newHeader[header + 1] = "";
        strncpy(newHeader, data, header);
        newHeader[header] = '\0';
        int headerValue = atoi(newHeader);
        if (headerValue > maxBytes) {
            body_length_ = 0;
            return false;
        }
        body_length_ = headerValue;
        return true;
    }

    size_t getBodyLength() { return body_length_; }

   private:
    int body_length_;
    char data[header + maxBytes];
};
#endif