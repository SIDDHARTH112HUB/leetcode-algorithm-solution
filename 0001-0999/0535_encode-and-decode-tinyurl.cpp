//Link: https://leetcode.com/problems/encode-and-decode-tinyurl/ 
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