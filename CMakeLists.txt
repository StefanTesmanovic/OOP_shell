cmake_minimum_required(VERSION 4.1)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        Processing/Shell.cpp
        Processing/Shell.h
        Processing/InputParser.cpp
        Processing/InputParser.h
        Processing/CommandFactory.cpp
        Processing/CommandFactory.h
        Commands/Command.cpp
        Commands/Command.h
        Commands/EchoCommand.cpp
        Commands/EchoCommand.h
        Commands/Pipe.cpp
        Commands/Pipe.h
        Commands/TimeCommand.cpp
        Commands/TimeCommand.h
        Commands/DateCommand.cpp
        Commands/DateCommand.h
        Commands/TouchCommand.cpp
        Commands/TouchCommand.h
        Commands/WcCommand.cpp
        Commands/WcCommand.h
)
