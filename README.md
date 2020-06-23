<p>
    <img src="logo.png" height="30"/>
</p>

# G. Meet Chat Crawler
this is a command-line application built to help you
know exacly who went to your meeting.

## Usage
Clone the repository and compile the "main.cpp" with your OS C++ 
compiler, here is an example on Linux with g++:

```bash
git clone https://github.com/guiguat/gmeet-chat-crawler.git
cd gmeet-chat-crawler
g++ main.cpp -o crawler
```

Then you will need to download your chat log file from Google Meet
and run the crawler with the first parameter being your file location as following:
```bash
./crawler ./chat-log.txt
```
