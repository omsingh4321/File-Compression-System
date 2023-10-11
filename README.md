# File Compression System Using Huffman Coding in C++
## Introduction
The project is to design compression and decompression programs using Huffman Coding. The idea is to assign variable length codes to input characters based on their frequencies. The more the frequency of the character the shorter the code assigned to it.
## Implementation
The program has been implemented in C++ language. The idea is to reduce the weighted expected storage by means of assigning shorter codes to frequently occurring characters.
## Compression:-
-->Provide the input.<br>
-->Note the frequency of all the characters in the input.<br>
-->Construct a min priority queue with respect to the frequencies of the characters.<br>
-->Construct Huffman Tree from the priority queue.<br>
-->Encode the file, store the encoding table and compress the input based on the encoding table.
### The codes are stored as bits and each character is provided a prefix code which is a string of bits(Encoding).
![image](https://github.com/omsingh4321/HuffmanCoding/assets/110286904/eab6bb01-69aa-42c7-9cf5-bef5d4f33580)
## Decompression:-
Open the file and reconstruct the Huffman Tree based on the Encoded table.<br>
Decode the file and store it to the desired file.
![image](https://github.com/omsingh4321/HuffmanCoding/assets/110286904/2931217b-fa06-4d23-b749-837bdb61dc4f)
## Output:-
![image](https://github.com/omsingh4321/HuffmanCoding/assets/110286904/5bbc61e8-04a5-4ae0-a56f-810e0ad6c103)
![image](https://github.com/omsingh4321/File-Compression-System/assets/110286904/6161f9f3-05c3-4bb8-8c35-ac30377aeb5f)


