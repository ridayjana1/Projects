Here's a `README.md` file you can use for your GitHub project. It will explain each step of the process in detail:

---

# Weather App

A simple command-line weather application that fetches real-time weather data for a specified city using the OpenWeatherMap API. The application is built in C++ and uses `libcurl` for making HTTP requests and `jsoncpp` for parsing JSON data.

## Features:
- Fetches weather information from OpenWeatherMap API.
- Displays weather data including temperature, humidity, wind speed, etc.
- Command-line interface to input city names.

---

## **Steps to Build and Run the Weather App**

### **1. Set Up the Project**

To build this project, you need to have a C++ compiler, along with the `libcurl` and `jsoncpp` libraries.

### **2. Install Dependencies**

This project uses two main dependencies:
- **libcurl**: A library for making HTTP requests.
- **jsoncpp**: A library for parsing and generating JSON data.

#### **macOS Installation:**
To install the dependencies on macOS, you can use **Homebrew**.

1. Open the Terminal.
2. Install `libcurl`:
   ```bash
   brew install curl
   ```
3. Install `jsoncpp`:
   ```bash
   brew install jsoncpp
   ```

#### **Windows Installation:**
On Windows, you need to manually download and install the libraries.

- **libcurl**: Download the `libcurl` library from [here](https://curl.haxx.se/download.html).
- **jsoncpp**: Download the `jsoncpp` library from [GitHub](https://github.com/open-source-parsers/jsoncpp).

Ensure that the include paths for these libraries are set up in your IDE or build system.

---

### **3. Clone the Repository**

Clone the repository to your local machine using the following command:

```bash
git clone https://github.com/ridayjana1/weather-app.git
```

Or you can download the repository as a ZIP file and extract it.

---

### **4. Compile the Code**

To compile the code, we use the `g++` compiler. Navigate to the project folder where the `main.cpp` file is located.

#### **macOS Compilation:**
In the Terminal, navigate to the project folder:
```bash
cd weather-app
```
Then compile the project:
```bash
g++ main.cpp -o weather -lcurl -ljsoncpp
```

#### **Windows Compilation:**
If you are using **MinGW**, navigate to the project folder and run:
```bash
g++ main.cpp -o weather.exe -lcurl -ljsoncpp
```

For **MSVC**, configure the Visual Studio project to link to the `libcurl` and `jsoncpp` libraries, then build the solution.

---

### **5. Run the Application**

#### **macOS Run:**
After compiling the code, you can run the application using:
```bash
./weather
```

#### **Windows Run:**
After compiling the code with **MinGW** or **MSVC**, you can run the application using:
```bash
weather.exe
```

---

### **6. Provide City Name**

When you run the program, it will prompt you to enter a city name:
```text
Enter city name: <YourCity>
```
Once you enter the city name, the program will fetch and display weather information for that city.

### **Sample Output:**
```
Weather in New York:
Temperature: 18°C
Humidity: 75%
Wind Speed: 5.5 m/s
```

---

## **How It Works**

1. **User Input**: The program prompts the user to enter a city name.
2. **API Request**: The program constructs a URL based on the city name and makes an HTTP GET request to the OpenWeatherMap API using `libcurl`.
3. **Parsing JSON**: The JSON response from the API is parsed using `jsoncpp` to extract relevant weather data such as temperature, humidity, and wind speed.
4. **Display Data**: The program displays the weather data to the user in a formatted output.

---

## **Additional Notes**

- **API Key**: To use the OpenWeatherMap API, you need an API key. If you don't already have one, you can sign up [here](https://openweathermap.org/api) to get your key.
- **Error Handling**: The app will show an error message if the city is not found or if there is a network issue.
- **Internet Access**: An active internet connection is required to fetch the weather data.

---

## **Contributing**

If you find any bugs or have suggestions for improvements, feel free to fork this repository and create a pull request. All contributions are welcome!

