
// Design and build a URL shortener service that can be used to shorten hundreds of millions of URLs -
//  assume this will support a company like Narvar that provides tracking of packages
//   to a few hundred top retailers. The service returns a short URL, given a longer URL;
//    and similarly redirects to the longer URL when given the short URL. As part of your solution, 
//    provide a brief technical document that outlines some of your design decisions such as storage choices,
//     choice of language, length of the short URL, rate limits etc. Extra points for
//      providing your solution in docker / kubernetes setup.

// Please have a look at the details and feel free to write/ call back in case of any queries?


#include <bits/stdc++.h>
using namespace std;

class shortener_service{
    private:
    map<string,int> longurl_hash;    // to store {id,long_url} pair
    char lettermap[27] ="abcdefghijklmnopqrstuvwxyz";   //to store actual character
    public:
    string getshort(string& long_url)
    {
        if(longurl_hash.find(long_url)!=longurl_hash.end())
        {
            int id=longurl_hash[long_url];
            string short_url=this->idtoshort(id);
            return short_url;

        }
        int id=longurl_hash.size()+1;   
        longurl_hash[long_url]=id;
        string short_url=this->idtoshort(id);
        return short_url;
    }
    string idtoshort(int id)
    {
        string short_url;
        while (id)
        {
            // in short url
            short_url.push_back(lettermap[id%26]);
            id = id/26;
        }
         // Reverse shortURL to complete base conversion
        reverse(short_url.begin(), short_url.end());
    
        return short_url;
    }


};
void requestservice(shortener_service& obj)
{
    string long_url;
    cin>>long_url;   //user input a long url or a seen as post request
    string short_url=obj.getshort(long_url); //returns short url
    cout<<short_url;


}
signed main() 
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    shortener_service obj;
    requestservice(obj);     //user puts a request this function will be called with obj passing
   
    
}