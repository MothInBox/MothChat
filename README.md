# MothChat

**MothChat** is a simple peer-to-peer (P2P) chat application written in C++ using Winsock2. It allows two users to exchange messages directly over TCP sockets, supporting both server and client modes. The project is designed for educational purposes and demonstrates basic socket programming, threading, and user interaction in a console environment.

---

## Features

* Peer-to-peer chat over TCP
* Simple username exchange on connection
* Multi-threaded message receiving
* Works on Windows (Visual Studio 2022, C++14)
* Supports both localhost and external connections (with port forwarding)

---

## Prerequisites

* Windows 10 or later
* Visual Studio 2022 (or compatible)
* C++14 or newer
* Winsock2 (included with Windows SDK)

---

## Building

### Using Visual Studio

1. Open the solution in Visual Studio (`p2pChat.sln`).
2. Build the solution (choose `Debug` or `Release`, `x64` recommended).

### Using MSBuild

1. Open **CMD** and navigate (`cd`) to the project folder.
2. Run:

   ```sh
   msbuild p2pChat.sln /p:Configuration=Release /p:Platform=x64
   ```

---

## Roadmap / Future Plans

### PGP Functionality

PGP (Pretty Good Privacy) is an encryption method using a pair of keys (public and private). The plan is to incorporate PGP into MothChat with both manual and network modes to allow for encrypted messaging.

---

## License

This project is released for **educational purposes**. Add your preferred license here (MIT, GPL, etc.) if you want to share/reuse.

