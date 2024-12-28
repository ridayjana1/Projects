#include <iostream>
#include <string>
#include <sstream>
#include <curl/curl.h>
#include <json/json.h>

using namespace std;

//This line casts userp to a string* and then uses the append method to add the data from contents to the string. The data size is size * nmemb.
//Purpose: userp is a pointer to a string where the fetched data will be stored. contents contains the data received by libcurl, and size * nmemb gives the total size of the data chunk.

size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

//This line defines a function named fetchData that takes a constant reference to a string named url and returns a string.
//Purpose: This function will fetch data from the given URL and return it as a string.

string fetchData(const string& url) {
    CURL* curl;
    CURLcode res;
//Explanation: Declares a variable res of type CURLcode.
//Purpose: CURLcode will store the result of the curl operations, which can be checked for success or failure.

    string readBuffer;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback); //This option sets the callback function that handles the response data (i.e., what to do with the data returned by the server).
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer); //This option tells libcurl where to store the data that it receives from the server.
        //This tells libcurl to write the data to the readBuffer string variable.

        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }
    return readBuffer;
}

void parseWeatherData(const string& data) { //to process and extract relevant weather information from the provided JSON string
    Json::Value jsonData; // JSON::Valus is a part of the JSON CPP library and represents a node in a JSON document. it can store diffrent type of data, such as strings, numbers, arrays and object
    Json::CharReaderBuilder reader; //JSON::CharReaderBuilder is used to construct a JSON reader, which will be used to parse the JSON string into JSON::Value obejct 
    string errs; //The string will store any error messages that occur during the parsing process

    istringstream stream(data); // istringstream is used to create a stream from the input string, allowing it to be prcessed by the jSOn parser
    if (!Json::parseFromStream(reader, stream, &jsonData, &errs)) {
        cout << "Failed to parse the JSON data: " << errs << endl;
        return; // This line attempts to convert the JSON string into a Json::Value object. If parsing fails, it stores the error messages in errs.
    }

    string city = jsonData["name"].asString(); //Extracts the value associated with the key "name" from jsonData and converts it to a string, storing it in the variable city.
    float temp = jsonData["main"]["temp"].asFloat();
    string weather = jsonData["weather"][0]["description"].asString();

    cout << "City: " << city << endl;
    cout << "Temperature: " << temp << " C" << endl;
    cout << "Weather: " << weather << endl;
}

int main() {
    string apiKey = "your api key from openweather.org";
    string city;
    cout << "Enter your city Name: ";
    getline(cin, city);
    string url = "http://api.openweathermap.org/data/2.5/weather?q=" + city + "&appid=" + apiKey + "&units=metric";
    string weatherData = fetchData(url);
    parseWeatherData(weatherData);

    return 0;
}
