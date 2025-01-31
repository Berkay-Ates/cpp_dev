g++ -g -o my_program my_program.cpp
gdb my_program
break main   # Set breakpoint at the start of main()
break 10     # Set breakpoint at line 10
break myFunction  # Break at function myFunction()

run