# Devexv-pipe-access
Soda's Pipe Access is a lightweight C++ library designed to facilitate HTTP communication and HTML retrieval from web servers using the Windows API (WinINet). Developed with simplicity and efficiency in mind, this library offers a streamlined interface for fetching HTML content from a predefined domain. 
Devexv's Pipe Access is a lightweight C++ library for fetching HTML content from web servers using the Windows API (WinINet). This library provides a simple and efficient way to communicate with web servers and retrieve HTML data within C++ applications running on the Windows platform.

## Features

- **HTTP Communication:** Establish HTTP connections and send requests to web servers.
- **HTML Retrieval:** Fetch HTML content from web pages hosted on the specified domain.
- **Synchronous Operation:** Perform synchronous operations to retrieve HTML content in a straightforward manner.
- **Windows API Integration:** Utilize the WinINet API for seamless integration with Windows-based applications.

## Installation

1. Clone the repository:

    ```
    git clone https://github.com/Devexv/Devexv-pipe-access.git
    ```

2. Include the necessary files (`Devexvs_pipe_access.h` and `Devexvs_pipe_access.cpp`) in your C++ project.

3. Ensure that your project is configured to link against the `wininet.lib` library.

## Usage

```cpp
#include "sodas_pipe_access.h"

int main() {
    // Create an instance of SodasPipeAccess
    SodasPipeAccess client;

    // Fetch HTML content from the specified domain
    std::string html = client.getHTML();

    // Display the retrieved HTML content
    std::cout << "HTML Content:" << std::endl;
    std::cout << html << std::endl;

    return 0;
} ```
