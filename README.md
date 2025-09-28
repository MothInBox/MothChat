# MothChat
**MothChat** is a simple peer-to-peer (P2P) chat application written in C++ using Winsock2. It allows two users to exchange messages directly over TCP sockets, supporting both server and client modes. The project is designed for educational purposes and demonstrates basic socket programming, threading, and user interaction in a console environment.

## Features
- Peer-to-peer chat over TCP
- Simple username exchange on connection
- Multi-threaded message receiving
- Works on Windows (Visual Studio 2022, C++14)
- Supports both localhost and external connections (with port forwarding)


### Prerequisites
- Windows 10 or later
- Visual Studio 2022 (or compatible)
- C++14 or newer
- Winsock2 (included with Windows SDK)

### Building
!using visual studio
Open the solution in Visual Studio (`p2pChat.sln`).
Build the solution (`Debug` or `Release`, `x64` recommended).

using msbuild
Open CMD and cd to the folder
msbuild p2pChat.sln /p:Configuration=Release /p:Platform=x64
