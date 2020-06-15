[535.encode-and-decode-tinyurl](https://leetcode.com/problems/encode-and-decode-tinyurl/)  

> Note: This is a companion problem to the [System Design](https://leetcode.com/discuss/interview-question/system-design/) problem: [Design TinyURL](https://leetcode.com/discuss/interview-question/124658/Design-a-URL-Shortener-(-TinyURL-)-System/).

TinyURL is a URL shortening service where you enter a URL such as `https://leetcode.com/problems/design-tinyurl` and it returns a short URL such as `http://tinyurl.com/4e9iAk`.

Design the `encode` and `decode` methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.  



**Solution:**  

```cpp
class Solution {
public:

    // Encodes a URL to a shortened URL.
    unordered_map<string, string> l2s, s2l;
    
    
    string encode(string longUrl) {
        string letters = "0123456789qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM";
        if( l2s.count(longUrl) )
            return l2s[longUrl];
        string shorturl;
        do{
            shorturl = "";
            for( int i = 0; i<6; i++ ){
                shorturl += letters[rand()%letters.size()];
            }
        }while( s2l.count(shorturl) > 0 );
        s2l[shorturl] = longUrl;
        l2s[longUrl]  = shorturl;
        return "http://tinyurl.com/" + shorturl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        if(shortUrl.size() <= 6 ) return "";
        string shortUri = shortUrl.substr(shortUrl.size()-6);
        if( s2l.count(shortUri) )
            return s2l[shortUri];
        return "";
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
```
      