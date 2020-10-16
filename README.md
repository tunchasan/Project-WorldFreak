## Project Profile
The high level goal of this project is to write a program called "wordfreak" that takes "some files" as input, counts how many times each word 
occurs across them all (considering all letters to be lower case), and writes those words and associated counts to an output file in alphabetical order.

#### ```$ ./wordfreak aladdin.txt```

Then the contents of the output file:

![enter image description here](https://i.hizliresim.com/fZ90PB.png)

The words from all the input files will be counted together. If a word appears 3 times in one input file and 4 times in another, it will be counted 7 times between the two. 

## Input
```wordfreak``` reads input from 3 sources: standard input, files given in argv, and a file given as the environment variable. 
It reads words from all these that are applicable (always standard in, sometimes the other 2). A working implementation accepts 
input entered directly into the terminal, with the end of such input signified by the EOF character (^D (control+d)): 

![enter image description here](https://i.hizliresim.com/vmccmS.png)

However, it alternately accepts a file piped in to standard input via bash’s operator pipe.

#### ```$ ./wordfreak aladdin.txt```

It sees information written to standard input. By just treating standard input like a file, the program gets both of these behaviours.

#### ```$ ./wordfreak aladdin.txt iliad.txt odyssey.txt```

Finally, a working implementation accepts an environment variable called WORD_FREAK set to a single file from
the command line to be analyzed:

#### ```$ WORD_FREAK=aladdin.txt ./wordfreak```

And of course, it can process all of these at once.

#### ```$ cat newton.txt | WORD_FREAK=aladdin.txt ./wordfreak iliad.txt odyssey.txt```

## Words
Words is comprised of only alpha characters, and all alpha characters should be taken to be lower case.
For example "POT4TO???" gives the words "pot" and "to". And the word "isn’t" is reading as "isn" and "t". While
this isn't necessarily intuitively correct, this is what the code is doing:

![enter image description here](https://i.hizliresim.com/WtpXIh.png)

The program stores the words in a specific data structure. A binary search tree for each letter 'a' to 'z'
that stores the words starting with that letter (and their counts). This can be thought of as a hash function from strings to
binary search trees, where the hashing function is just first_letter - 'a'. Note that these BSTs will not likely be balanced; that
is fine.

## Output
The words are written to the file alphabetically (the BSTs make this fairly trivial). Each word will give a line of the form
"[word][additional space] : [additional space][number]\n". The caveat is that all the colons are lined up. The words are
left-aligned and the longest will have a single space between its end and the colon (note "respectfully" in the example
below); the numbers are right-aligned and the longest will have a single space between the colon and its beginning (note
126 in the example below).

![enter image description here](https://i.hizliresim.com/0pcExw.png)

The output file is named output.txt. When opening the file to write to, the program will either use to create the file
or remove all existing contents, so make use of open()'s O_CREAT and O_TRUNC. Moreover, We want the file’s permissions to be set so that it can be read. open()’s third argument determines permissions of created files, something like0644 will make it readable.

### make

The console app uses Makefile to manage folder and running processes. So the app can be run via cmd with "make" command on project folder' directory.

