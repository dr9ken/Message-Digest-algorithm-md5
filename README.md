# Message-digest algorithm md5
Implementation of the MD5 data hashing algorithm

More about the algorithm: https://en.wikipedia.org/wiki/MD5

Application:
1. Connecting the md5.h library
	* algorithm uses a self-written queue, which must be added to the project (queue.cpp)
	* algorithm uses a self-written stack, which must be added to the project (stack.cpp)
2. Call function MD5
	* the path to the file with text is passed to the function
3. The function returns a value, storing a 16-byte hash consisting of 32 hexadecimal digits
