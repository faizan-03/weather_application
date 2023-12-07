#include<iostream>
#include<string>
#include<string.h>
#include<ctime>
#include<vector>
#include<fstream>
#include<windows.h>
#include<conio.h>
#include <iomanip>
#include <thread>
#include <chrono>
#include <sstream>
#include <cctype>

// weather forcast application 22021519-040 Faizan Ali


using namespace std;

// global variable 

bool flag = false;

// animation 

void process() {

	int numDots = 3;

	cout << "PROCESSING ";

	for (int i = 0; i < numDots; ++i) {
		cout << " .";
		cout.flush();

		Sleep(700);
	}
	system("cls");

}

// animation

void exiting() {

	int numDots = 3;

	cout << "EXITING ";

	for (int i = 0; i < numDots; ++i) {
		cout << " .";
		cout.flush();

		Sleep(700);
	}
	system("cls");

}

// colors

void color(int a)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console, a);
}

// exceptions

int GetNumber(int len)
{
	char strNum[11];
	char ch;
	int i = 0;
	bool hasDigit = false;

	while (i < len)
	{
		ch = _getch();

		if (ch >= '0' && ch <= '9')
		{
			cout << ch;
			strNum[i] = ch;
			i++;
			hasDigit = true;
		}
		else if (ch == '\r')
		{
			if (hasDigit)
				break;
		}
		else if (ch == '\b' && i > 0)
		{
			cout << "\b \b";
			i--;
			hasDigit = false;
			for (int j = 0; j < i; j++)
			{
				if (strNum[j] >= '0' && strNum[j] <= '9')
				{
					hasDigit = true;
					break;
				}
			}
		}
	}

	cout << "\n";
	strNum[i] = '\0';

	return atoi(strNum);
}

//exceptions

string GetString()
{
	const int maxLength = 100;
	char input[maxLength];
	int i = 0;
	char ch;

	while (i < maxLength)
	{
		ch = _getch();
		if (isalpha(ch) || ch == ' ')
		{
			cout << ch;
			input[i] = ch;
			i++;
		}
		if (ch == '\r')
		{
			if (i > 2)
				break;
		}
		if (ch == '\b' && i > 0)
		{
			cout << "\b \b";
			i--;
		}
	}

	input[i] = '\0';
	cout << "\n";

	return string(input);
}

// getdata on middle of console

int getConsoleWidth()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	return csbi.dwSize.X;
}

// startup animation 

void centerText(const string& text, int color)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;

	stringstream ss(text);
	string line;
	vector<string> lines;
	int maxLineLength = 0;

	while (getline(ss, line)) {
		int lineLength = static_cast<int>(line.length());
		if (lineLength > maxLineLength) {
			maxLineLength = lineLength;
		}
		lines.push_back(line);
	}

	for (const auto& line : lines) {
		int padding = (consoleWidth - maxLineLength) / 2;
		for (int j = 0; j < padding; j++) {
			cout << " ";
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
		cout << line << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // Reset to default color
	}
}

// blink 

void blink(const string& text, int color, int blinkCount) {
	for (int i = 0; i < blinkCount; i++) {
		system("cls");
		centerText(text, color);
		this_thread::sleep_for(chrono::milliseconds(300));
		system("cls");
		this_thread::sleep_for(chrono::milliseconds(300));
	}
}

//  helping to get present date 

class Date {

private:

	time_t current_time;
public:

	string  month;
	int day;
	int year;

	void set_time()
	{

		current_time = time(nullptr);
		tm currentDate;
		localtime_s(&currentDate, &current_time);
		char date[20];
		strftime(date, sizeof(date), "%d %b %Y", &currentDate);
		string bufferString(date);
		day = stoi(bufferString.substr(0, 2));
		month = bufferString.substr(3, 3);
		for (char& c : month) {
			c = toupper(c);
		}
		year = stoi(bufferString.substr(7, 4));
	}


	Date()
	{
		set_time();
	}
	// display date
	void dddd() {

		cout << day << "/" << month << "/" << year;
	}
};


// base abstract class sensor

class SENSOR {
public:

	int sensor_id;
	string sensor_company;
	Date date;


	virtual void get_sensorinfo() = 0;

};

// child class 

class wind_sensor :public SENSOR {

public:

	int wind_speed;

	// get_data

	void get_windspeed()

	{
		if (this->date.month == "JAN") {
			wind_speed = 8 + (rand() % 5);
		}
		else if (this->date.month == "FEB") {
			wind_speed = 10 + (rand() % 5);
		}
		else if (this->date.month == "MAR") {
			wind_speed = 12 + (rand() % 6);
		}
		else if (this->date.month == "APR") {
			wind_speed = 15 + (rand() % 6);
		}
		else if (this->date.month == "MAY") {
			wind_speed = 18 + (rand() % 6);
		}
		else if (this->date.month == "JUN") {
			wind_speed = 21 + (rand() % 7);
		}
		else if (this->date.month == "JUL") {
			wind_speed = 23 + (rand() % 8);
		}
		else if (this->date.month == "AUG") {
			wind_speed = 21 + (rand() % 7);
		}
		else if (this->date.month == "SEP") {
			wind_speed = 18 + (rand() % 6);
		}
		else if (this->date.month == "OCT") {
			wind_speed = 15 + (rand() % 6);
		}
		else if (this->date.month == "NOV") {
			wind_speed = 12 + (rand() % 6);
		}
		else if (this->date.month == "DEC") {
			wind_speed = 10 + (rand() % 5);
		}
		else
			cout << " ENTER VALID MONTH" << endl;


	}

	void get_sensorinfo() {

		string company[10] =
		{ "WeatherSense ","ClimateTech ","StormTrack ",
		"SkyMetrix","WeatherWise","WeatherTech",
		"WindGuard","RainSense","WeatherData",
		"WeatherMetrics"
		};

		sensor_id = 10000000 + rand() % 90000000;
		int num;
		num = 0 + rand() % 9;
		sensor_company = company[num];

	}


};

// child class

class temp_sensor :public SENSOR
{
public:

	int* temperature;

	temp_sensor() {

		temperature = new int;
	}

	~temp_sensor() {

		delete temperature;
	}

	void get_temp()

	{
		if (this->date.month == "JAN") {
			*temperature = 6 + (rand() % 12);
		}
		else if (this->date.month == "FEB") {
			*temperature = 9 + (rand() % 10);
		}
		else if (this->date.month == "MAR") {
			*temperature = 14 + (rand() % 13);
		}
		else if (this->date.month == "APR") {
			*temperature = 19 + (rand() % 10);
		}
		else if (this->date.month == "MAY") {
			*temperature = 23 + (rand() % 15);
		}
		else if (this->date.month == "JUN") {
			*temperature = 29 + (rand() % 13);
		}
		else if (this->date.month == "JUL") {
			*temperature = 29 + (rand() % 15);
		}
		else if (this->date.month == "AUG") {
			*temperature = 27 + (rand() % 10);
		}
		else if (this->date.month == "SEP") {
			*temperature = 24 + (rand() % 10);
		}
		else if (this->date.month == "OCT") {
			*temperature = 18 + (rand() % 13);
		}
		else if (this->date.month == "NOV") {
			*temperature = 11 + (rand() % 14);
		}
		else if (this->date.month == "DEC") {
			*temperature = 6 + (rand() % 14);
		}
		else
			cout << " ENTER VALID MONTH" << endl;

	}

	void get_sensorinfo() {

		string company[10] =
		{ "WeatherSense ","ClimateTech ","StormTrack ",
		"SkyMetrix","WeatherWise","WeatherTech",
		"WindGuard","RainSense","WeatherData",
		"WeatherMetrics"
		};

		sensor_id = 10000000 + rand() % 90000000;
		int num;
		num = 0 + rand() % 9;
		sensor_company = company[num];

	}

};

// child class

class humid_sensor :public SENSOR {

public:

	int humidity;

	void get_humidity()

	{
		if (this->date.month == "JAN") {

			humidity = 60 + (rand() % 10);
		}
		else if (this->date.month == "FEB") {
			humidity = 56 + (rand() % 10);
		}
		else if (this->date.month == "MAR") {
			humidity = 47 + (rand() % 13);
		}
		else if (this->date.month == "APR") {
			humidity = 41 + (rand() % 10);
		}
		else if (this->date.month == "MAY") {
			humidity = 20 + (rand() % 10);
		}
		else if (this->date.month == "JUN") {
			humidity = 29 + (rand() % 13);
		}
		else if (this->date.month == "JUL") {
			humidity = 20 + (rand() % 15);
		}
		else if (this->date.month == "AUG") {
			humidity = 26 + (rand() % 10);
		}
		else if (this->date.month == "SEP") {
			humidity = 22 + (rand() % 10);
		}
		else if (this->date.month == "OCT") {
			humidity = 34 + (rand() % 10);
		}
		else if (this->date.month == "NOV") {
			humidity = 40 + (rand() % 10);
		}
		else if (this->date.month == "DEC") {
			humidity = 46 + (rand() % 10);
		}
		else
			cout << " ENTER VALID MONTH " << endl;
	};

	void get_sensorinfo() {

		string company[10] =
		{ "WeatherSense ","ClimateTech ","StormTrack ",
		"SkyMetrix","WeatherWise","WeatherTech",
		"WindGuard","RainSense","WeatherData",
		"WeatherMetrics"
		};

		sensor_id = 10000000 + rand() % 90000000;
		int num;
		num = 0 + rand() % 9;
		sensor_company = company[num];
	}

};

// child class

class light_sensor :public SENSOR

{

public:

	int light_intensity;
	string* day;

	light_sensor() {


		day = new string[10];
		this->day[0] = "light";

	}
	~light_sensor() {

		delete[] day;

	}
	void get_light()
	{
		light_intensity = 1 + (rand() % 100);
		if (light_intensity >= 21) {
			this->day[0] = " SUNNY ";
		}
		else
			this->day[0] = " CLOUDLY ";
	};

	void get_sensorinfo() {

		string company[10] =
		{ "WeatherSense ","ClimateTech ","StormTrack ",
		"SkyMetrix","WeatherWise","WeatherTech",
		"WindGuard","RainSense","WeatherData",
		"WeatherMetrics"
		};

		sensor_id = 10000000 + rand() % 90000000;
		int num;
		num = 0 + rand() % 9;
		sensor_company = company[num];
	}


};

// child class

class rain_sensor :public SENSOR {

public:

	int rain_percentage;
	int rain;
	friend class light_sensor;
	friend class temp_sensor;
	void get_raininfo()
	{
		light_sensor l;
		temp_sensor t;

		if (l.day[0] == " CLOUDLY " && *t.temperature <= 30)
		{
			rain_percentage = 55 + rand() % 45;
		}
		else
			rain_percentage = 1 + rand() % 45;

		if (rain_percentage >= 50)
			rain = 1 + rand() % 8;
		else
			rain = 00;

	};

	void get_sensorinfo() {

		string company[10] =
		{ "WeatherSense ","ClimateTech ","StormTrack ",
		"SkyMetrix","WeatherWise","WeatherTech",
		"WindGuard","RainSense","WeatherData",
		"WeatherMetrics"
		};

		sensor_id = 10000000 + rand() % 90000000;
		int num;
		num = 0 + rand() % 9;
		sensor_company = company[num];

	}

};

// main class

class STATION_MANAGMENT {

public:

	int ncount;
	string read;
	int count_line;
	bool flag;
	string city;

	string cities[130] = {
		"KARACHI", "LAHORE", "FAISALABAD", "RAWALPINDI", "MULTAN",
		"HYDERABAD", "GUJRANWALA", "PESHAWAR", "ABBOTTABAD", "ISLAMABAD",
		"QUETTA", "SIALKOT", "BAHAWALPUR", "SARGODHA", "SUKKUR",
		"LARKANA", "SHEIKHUPURA", "RAHIM YAR KHAN", "JHANG", "GUJRAT",
		"KASUR", "MARDAN", "MINGORA", "DERA GHAZI KHAN", "NAWABSHAH",
		"SAHIWAL", "MIRPUR KHAS", "OKARA", "MANDI BAHAUDDIN", "JACOBABAD",
		"SADDIQABAD", "KOHAT", "MURIDKE", "KHANEWAL", "GOJRA",
		"BAHAWALNAGAR", "PAKPATTAN", "JARANWALA", "KAMOKE", "CHINIOT",
		"SADIQABAD", "DASKA", "BUREWALA", "WAZIRABAD", "KHUSHAB",
		"CHARSADDA", "SWABI", "ABBOTTABAD", "MIANWALI", "TANDO ADAM",
		"KOT ADU", "HARIPUR", "MANSEHRA", "CHAMAN", "CHARSADDA",
		"NOWSHERA", "HUB", "MUZAFFARGARH", "KHUZDAR", "GHOTKI",
		"KOHLU", "BHAKKAR", "KASUR", "MUZAFFARABAD", "DADU",
		"MIAN CHANNU", "TIMERGARA", "UMARKOT", "HASILPUR", "HANGU",
		"BADIN", "LORALAI", "PANO AQIL", "KANDHKOT", "KARAK",
		"MASTUNG", "KOTLI", "MANSEHRA", "QILA ABDULLAH", "KHAIRPUR",
		"BANNU", "CHAKWAL", "TURBAT", "MANDI BAHAUDDIN", "SHAHDADKOT",
		"HARIPUR", "SHIKARPUR", "RAWALA KOT", "HAFIZABAD", "LAKKI MARWAT",
		"KHANPUR", "KABAL", "GWADAR", "KHUZDAR", "KULACHI",
		"WAZIRABAD", "CHAKWAL", "KHARIAN", "MARDAN", "LEIAH",
		"PAKPATTAN", "TOBA TEK SINGH", "HAROONABAD", "KAMALIA", "SHAHDADPUR",
		"NANKANA SAHIB", "NAUSHAHRO FIROZ", "NEW MIRPUR", "TALAGANG", "RAJANPUR",
		"UPPER DIR", "TANDO ALLAHYAR", "VEHARI", "MEHAR", "PINDI BHATTIAN",
		"KARAK", "KOT MALIK BARKHURDAR", "LODHRAN", "ARIFWALA", "LALA MUSA",
		"JARANWALA", "SHAHPUR", "NAROWAL", "SHABQADAR", "LAHORE",
		"GUJRANWALA", "FAISALABAD", "SIALKOT", "RAWALPINDI", "MULTAN"
	};

	static void menu()
	{
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "\t\t\t\t\t==========================================\n";
		cout << "\t\t\t\t\t||                                      ||\n";
		cout << "\t\t\t\t\t||                                      ||\n";
		cout << "\t\t\t\t\t||  1. TO ADD STATION	                ||\n";
		cout << "\t\t\t\t\t||  2. TO DELETE STATION	        ||\n";
		cout << "\t\t\t\t\t||  3. TO SEE  STATION FORECAST         ||\n";
		cout << "\t\t\t\t\t||  4. TO STATION INFORMATION           ||\n";
		cout << "\t\t\t\t\t||  5. TO EXIT                          ||\n";
		cout << "\t\t\t\t\t||                                      ||\n";
		cout << "\t\t\t\t\t||                                      ||\n";
		cout << "\t\t\t\t\t==========================================\n";
	}

	int serchcity() {


		int numCities = 130;
		int numRows = 5;
		int numCols = 5;

		cout << endl;
		for (int i = 0; i < numCities; i += numCols)
		{
			for (int j = 0; j < numCols; j++)
			{
				int cityIndex = i + j;
				if (cityIndex < numCities)
				{

					cout << setw(4) << i + j + 1 << ". " << setw(15) << cities[cityIndex] << "  ";
				}
			}
			cout << endl;
		}
		cout << endl;

		while (true)
		{
			cout << " ENTER THE INDEX NUMBER ";
			ncount = GetNumber(4);
			if (ncount > 0 && ncount < 131) {
				break;
			}
			cout << " YOU ENTER WRONG INPUT. PLZ TRY AGAIN \n";
			cout << endl;
		}
		return ncount;
	}


	STATION_MANAGMENT() {

		this->count_line = 1;
		this->flag = 0;
		this->city = "GUJRAT";

	}


	// file handling 

	int count_cities(const string& name)
	{
		ifstream file(name);
		if (!file.is_open()) {
			cout << "ERROR: File not found." << endl;
			return 0;
		}

		string output;
		int cityCount = 0;
		while (getline(file, output)) {
			cityCount++;
		}

		file.close();
		return cityCount;
	}

	void view_station(const string& name) {

		int cityCount = count_cities(name);

		if (cityCount == 0) {

			cout << " THERE ARE NO STATION ADDED " << endl;
			return;
		}
		else {
			fstream file(name);

			if (file.is_open()) {

				count_line = 1;

				while (getline(file, read)) {

					cout << count_line << " " << read << endl;
					count_line++;
				}
				file.close();
				count_line = 1;
			}
			else
				cout << " FILE NOT OPEN TO READ " << endl;
		}
	}

	string station_forecast(const string& name) {

		int c = count_cities(name);
		int a;
		while (true)
		{
			cout << " ENTER CITY INDEX " << endl;
			a = GetNumber(2);
			if (a > 0 && a <= c) {
				break;
			}

			cout << " PLZ ENTER VALID INPUT " << endl;
			cout << endl;
		}

		fstream filee(name);
		if (filee.is_open()) {
			count_line = 1;
			while (getline(filee, read)) {
				if (count_line == a) {
					city = read;
					break;
				}
				count_line++;
			}
			filee.close();
			count_line = 1;
		}
		else
			cout << " FILE NOT OPEN TO READ " << endl;

		return city;
	}

	// write file

	void add_station(const string& name)
	{
		ifstream file(name);
		bool flag1 = false;
		int cityCount = count_cities(name);

		if (cityCount > 11)
		{
			cout << "CANNOT ADD MORE STATIONS. LIMIT MAX REACHED." << endl;
			return;
		}
		if (file.is_open()) {

			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << endl;
			cout << "\t\t\t\t\t==========================================\n";
			cout << "\t\t\t\t\t||                                      ||\n";
			cout << "\t\t\t\t\t||                                      ||\n";
			cout << "\t\t\t\t\t||  1. TO ADD BY NAME		        ||\n";
			cout << "\t\t\t\t\t||  2. TO ADD BY INDEX	                ||\n";
			cout << "\t\t\t\t\t||  3. TO EXIT                          ||\n";
			cout << "\t\t\t\t\t||                                      ||\n";
			cout << "\t\t\t\t\t||                                      ||\n";
			cout << "\t\t\t\t\t==========================================\n";
			int n;
			cout << endl;
			cout << " ENTER NUMBER ";
			n = GetNumber(1);
			cout << endl;
			switch (n)
			{
			case 1:
			{
				process();
				color(9);
				cout << "ENTER STATION OR CITY NAME: ";
				city = GetString();
				for (char& c : city)
				{
					c = toupper(c);
				}
				file.close();
				for (int i = 0; i < 153; i++) {
					if (cities[i] == city) {
						flag1 = true;
						break;
					}
				}
			}
			break;
			case 2:
			{
				process();
				color(10);
				int k = 0; k = serchcity();
				city = cities[k - 1];
				flag1 = true;
			}
			break;
			case 3:
				exiting();
				//exit(0);
				break;
			default:
				cout << " INVALID INPUT . ENTER VALID INPUT \n";

			}


			file.close();

			if (flag1)
			{
				ofstream outFile(name, ios::app);
				if (outFile.is_open())
				{
					outFile << city << endl;
					outFile.close();
					cout << endl;
					cout << " ----CITY ADDED SUCCESSFULLY---- " << endl;
					cout << endl;
				}
				else
				{
					cout << "UNABLE TO OPEN FILE FOR ADDING CITY." << endl;
				}
			}
			else
			{
				cout << "CITY NOT FOUND IN THE LIST OF PREDEFINED CITIES." << endl;
			}
		}
		else
		{
			cout << "FILE NOT OPEN TO READ." << endl;
		}
	}

	// update file 

	void delete_station(const string& name) {

		int c = count_cities(name);
		int num;
		while (true)
		{
			cout << " ENTER STATION NUMBER YOU WANT TO DELETE ";
			num = GetNumber(2);
			if (num > 0 && num <= c) {
				break;
			}

			cout << " PLZ ENTER VALID INPUT " << endl;
			cout << endl;
		}
		process();
		//cin.ignore();
		fstream file(name);
		vector<string>dlt;

		if (file.is_open())
		{
			count_line = 1;
			while (getline(file, read))
			{

				if (count_line != num)
				{
					dlt.push_back(read);
				}

				count_line++;
			}
			file.close();

			fstream fil(name, ios::trunc | ios::out);
			if (fil.is_open())
			{

				for (const auto& data : dlt)
				{

					fil << data << endl;
				}
				fil.close();
				cout << endl;
				cout << " FILE UPDATED SUCCESSFULLY " << endl;
				cout << "---------------------------" << endl;
			}
			else
				cout << " ENABLE TO OPEN FILE FOR DELETATION " << endl;
		}
		else
			cout << " UNABLE TO OPEN FOR READ DATA " << endl;
	};


};

// station class 

class STATION {

public:
	int num;
	int longitude;
	int latitude;
	double xlon[130] = {
			67.0099, 74.3587, 73.0772, 73.0479, 71.4711,
			68.3750, 74.1993, 71.5249, 73.2520, 73.0479,
			66.9750, 74.5435, 71.6750, 72.6711, 68.8566,
			68.2063, 73.9783, 70.3116, 72.3358, 74.0818,
			74.4450, 72.0359, 72.3649, 70.4381, 68.4770,
			73.0965, 69.0119, 73.4519, 73.4849, 68.4360,
			70.1274, 71.4410, 74.2814, 71.9329, 72.6831,
			73.2472, 73.9783, 73.0651, 74.0760, 72.9805,
			70.1274, 75.9828, 72.6711, 75.9938, 73.0489,
			71.0759, 72.2594, 66.9961, 72.3692, 66.6529,
			73.5461, 72.9607, 72.3447, 73.7712, 72.9581,
			71.8792, 66.7536, 68.8694, 67.8766, 73.4213,
			70.6470, 71.8765, 73.0243, 69.1737, 68.7754,
			70.9246, 73.0702, 66.9825, 68.4458, 73.0833,
			72.8534, 71.8749, 67.7236, 73.3923, 73.2559,
			70.4728, 71.0748, 63.0360, 67.0128, 72.9556,
			70.3800, 70.4871, 69.6083, 67.8962, 71.1894,
			73.0449, 70.9193, 68.3986, 72.3593, 72.3594,
			66.9750, 71.8712, 80.2530, 70.9450, 72.9603,
			70.1063, 73.5616, 72.3788, 73.1389, 72.9888,
			71.1984, 72.7979, 67.9209, 70.9114, 73.1391,
			73.0506, 73.0412, 71.5632, 74.2051, 73.2283,
			70.4662, 70.7577, 73.1395, 72.9426, 74.3587,
			74.1993, 73.0772, 73.0479, 71.4711, 74.3587,
			70.4662, 70.7577, 73.1395, 72.9426, 74.3587,
			74.1993, 73.0772, 73.0479, 71.4711, 74.3587,
	};
	double ylat[130] = {

		24.8615, 31.5204, 31.4504, 33.6058, 30.1974,
		25.3969, 32.1604, 34.0151, 34.1464, 33.6844,
		30.1798, 32.4920, 29.3956, 32.0836, 27.7058,
		27.5615, 31.7131, 28.4202, 31.2710, 32.5723,
		31.1150, 34.2019, 34.7717, 30.0455, 26.2442,
		30.6653, 25.5268, 30.8109, 32.5863, 28.2818,
		28.3002, 33.5861, 31.8032, 30.3026, 31.1471,
		29.9985, 31.7131, 31.3342, 32.7021, 32.7196,
		28.3002, 32.3359, 30.1503, 32.4416, 32.2969,
		35.4167, 34.0216, 36.5979, 32.5747, 28.0417,
		33.4500, 31.7322, 33.0139, 31.8020, 33.7086,
		31.8111, 25.1231, 28.4300, 25.3488, 30.8265,
		33.4691, 29.3786, 32.5833, 36.7389, 28.0064,
		32.5566, 31.9129, 32.5804, 31.1531, 33.1253,
		32.2881, 32.9278, 27.8006, 25.1386, 32.4536,
		34.1673, 32.9356, 27.8404, 34.1498, 31.1699,
		32.9866, 32.9293, 25.1252, 27.8500, 31.9209,
		31.7190, 34.0164, 26.2454, 25.5147, 30.3915,
		33.4708, 32.4423, 31.2532, 25.3764, 34.2116,
		34.7489, 33.2998, 25.1351, 29.6334, 31.5451,
		32.2221, 30.8017, 34.0868, 33.6379, 30.6993,
		31.7131, 31.8447, 32.1027, 31.8815, 31.5204,
		32.1604, 31.4504, 33.6058, 30.1974, 34.2116,
		33.4708, 32.4423, 31.2532, 25.3764, 34.2116,
		34.7489, 33.2998, 25.1351, 29.6334, 31.5451,
	};

	int i;

	// 

	STATION_MANAGMENT management;

	temp_sensor* t = new temp_sensor;
	wind_sensor* w = new wind_sensor;
	light_sensor* l = new light_sensor;
	rain_sensor* r = new  rain_sensor;
	humid_sensor* h = new humid_sensor;


	STATION()
	{

		latitude = 32;
		longitude = 74;
		num = 0;
	}

	~STATION()
	{
		delete t;
		delete w;
		delete l;
		delete r;
		delete h;

	}

	static void menubysearch()
	{
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "\t\t\t\t\t==========================================\n";
		cout << "\t\t\t\t\t||                                      ||\n";
		cout << "\t\t\t\t\t||                                      ||\n";
		cout << "\t\t\t\t\t||  1. TO SEARCH BY NAME OF CITY        ||\n";
		cout << "\t\t\t\t\t||  2. TO SEARCH BY INDEX OF CITY       ||\n";
		cout << "\t\t\t\t\t||  3. TO MAIN                          ||\n";
		cout << "\t\t\t\t\t||                                      ||\n";
		cout << "\t\t\t\t\t||                                      ||\n";
		cout << "\t\t\t\t\t==========================================\n";

	}

	void searchCITY() {

		cin.clear();
		cout << " ENTER CITY NAME : ";
		management.city = GetString();
		for (char& c : management.city) {
			c = toupper(c);
		}

	}

	void SET_ADDRESS() {

		bool flag1 = 0;

		for (i = 0; i < 153; i++)
		{

			if (management.cities[i] == management.city)
			{
				flag1++;
				flag = true;
				break;
			}
			flag1 = 0;
			flag = false;
		}
		if (flag1 != 0)
		{
			this->longitude = xlon[i];
			this->latitude = ylat[i];
		}


	};

	void setfromarr()
	{
		int num = management.serchcity();
		management.city = management.cities[num - 1];
		longitude = xlon[num - 1];
		latitude = ylat[num - 1];
		flag = true;
	}

	void live_loc(const string& name) {

		if (flag) {

			fstream input(name, ios::out);

			if (input.is_open())
			{
				input << management.city;
				cout << endl;
				cout << "---- CITY CHANGED SUCCESSFULLY ----" << endl;
			}
			input.close();
		}
		else
			cout << " ---- CITY NOT FOUND ---- " << endl;

	}

	string read_livloc(const string& name) {

		ifstream output(name);
		string a;
		if (output.is_open())
		{
			output >> a;
			management.city = a;
			output.close();
		}
		else
			cout << " FILE NOT OPEN " << endl;

		return management.city;
	}

	void station_info(const string& name, const string& name2) {

		management.view_station(name);

		int c = management.count_cities(name);
		cout << endl;
		while (true)
		{
			cout << " ENTER THE INDEX TO KNOW THE INFORMATION OF STATION  " << endl;
			num = GetNumber(2);
			if (num > 0 && num <= c)
			{
				break;
			}

			cout << " PLZ ENTER VALID INPUT " << endl;
			cout << endl;
		}
		cout << endl;


		fstream filee(name);

		if (filee.is_open())
		{
			int count_line = 1;
			while (getline(filee, management.read))
			{
				if (count_line == num)
				{
					management.city = management.read;
					break;
				}
				count_line++;
			}

			filee.close();
			count_line = 1;
		}
		else
		{
			cout << " FILE NOT OPEN TO READ " << endl;
		}

		fstream nsta(name2);

		if (nsta.is_open())
		{
			nsta << management.city << "  STATION " << endl;
			t->get_sensorinfo();
			nsta << " THE ID OF TEMPERATURE SENSOR IS " << t->sensor_id << endl;
			nsta << " THE COMPANY OF TEMPERATURE SENSOR IS " << t->sensor_company << endl;
			w->get_sensorinfo();
			nsta << " THE ID OF WIND SENSOR IS " << w->sensor_id << endl;
			nsta << " THE COMPANY OF WIND SENSOR IS " << w->sensor_company << endl;
			l->get_sensorinfo();
			nsta << " THE ID OF LIGHT SENSOR IS " << l->sensor_id << endl;
			nsta << " THE COMPANY OF LIGHT SENSOR IS " << l->sensor_company << endl;
			r->get_sensorinfo();
			nsta << " THE ID OF RAIN SENSOR IS " << r->sensor_id << endl;
			nsta << " THE COMPANY OF RAIN SENSOR IS " << r->sensor_company << endl;
			h->get_sensorinfo();
			nsta << " THE ID OF HUMIDITY SENSOR IS " << h->sensor_id << endl;
			nsta << " THE COMPANY OF HUMIDITY SENSOR IS " << h->sensor_company << endl;
			nsta.close();
		}
		else
			cout << " FILE NOT OPEN TO WRITE " << endl;
	}

	void ReadSeninfo(const string& name) {

		fstream sta(name);

		if (sta.is_open())
		{

			cout << endl;
			cout << "===============================================\n";
			cout << "||					\n";
			cout << "||					\n";
			while (getline(sta, management.read))
			{
				cout << "||  "; cout << management.read; cout << endl;
				cout << "|| " << endl;
			}
			sta.close();
			cout << "||					\n";
			cout << "||					\n";
			cout << "================================================\n";
		}
		else
			cout << " FILE NOT OPEN TO SHOW DATA " << endl;
			
	}


};


// weather class 

class WEATHER_FORECAST
{

public:

	STATION station;

	// aggregation

	Date* date = new Date;

	static void liveMenu()
	{
		color(4);
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "\t\t\t\t\t==========================================\n";
		cout << "\t\t\t\t\t||                                      ||\n";
		cout << "\t\t\t\t\t||                                      ||\n";
		cout << "\t\t\t\t\t||  1. TO SEE LIVE LOCATION             ||\n";
		cout << "\t\t\t\t\t||  2. TO CHANGE LIVE LOCATION          ||\n";
		cout << "\t\t\t\t\t||  3. TO EXIT                          ||\n";
		cout << "\t\t\t\t\t||                                      ||\n";
		cout << "\t\t\t\t\t||                                      ||\n";
		cout << "\t\t\t\t\t==========================================\n";
	}

	static void datemenu() {

		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << "\t\t\t\t\t=====================================================\n";
		cout << "\t\t\t\t\t||                                                 ||\n";
		cout << "\t\t\t\t\t||                                                 ||\n";
		cout << "\t\t\t\t\t||  1. TO SEE WEATHER OF PRESENT CITY              ||\n";
		cout << "\t\t\t\t\t||  2. TO SEE WEATHER OF CITY BY SEARCH THAT DATE  ||\n";
		cout << "\t\t\t\t\t||  3. TO SEE WEATHER OF CITY BY INDEX THAT DATE   ||\n";
		cout << "\t\t\t\t\t||  4. TO EXIT                                     ||\n";
		cout << "\t\t\t\t\t||                                                 ||\n";
		cout << "\t\t\t\t\t||                                                 ||\n";
		cout << "\t\t\t\t\t=====================================================\n";

	}

	void searchBydate()
	{
		string mon;
		bool flag2 = false;

		while (true)
		{
			cout << " ENTER A MONTH : ";
			mon = GetString();

			date->month = mon.substr(0, 3);
			for (char& c : date->month)
			{
				c = toupper(c);
			}

			if (date->month == "JAN" || date->month == "FEB" || date->month == "MAR" || date->month == "APR" ||
				date->month == "MAY" || date->month == "JUN" || date->month == "JUL" || date->month == "AUG" ||
				date->month == "SEP" || date->month == "OCT" || date->month == "NOV" || date->month == "DEC")
			{
				break;
			}

			cout << " YOU ENTER WRONG INPUT KINDLY CORRECT IT \n";
			cout << endl;

		}
		cout << endl;

		// exception handling 

		while (true)
		{
			cout << "ENTER A DAY : ";
			date->day = GetNumber(2);
			if (date->month == "MAR" || date->month == "MAY" || date->month == "JUL" ||
				date->month == "AUG" || date->month == "OCT" || date->month == "DEC")
			{
				if (date->day > 0 && date->day <= 31)
				{
					flag2 = true;
					break;
				}
			}
			if (date->month == "FEB")
			{
				if (date->day > 0 && date->day < 29)
				{
					flag2 = true;
					break;
				}

			}
			if (date->month == "JAN" || date->month == "APR" ||
				date->month == "JUN" || date->month == "SEP" || date->month == "NOV")
			{
				if (date->day > 0 && date->day < 31)
				{
					flag2 = true;
					break;
				}

			}


			cout << "YOU ENTERED A WRONG NUMBER . PLEASE TRY AGAIN \n" << endl;
			cout << endl;
		}
		cout << endl;

		while (true)
		{
			cout << " ENTER A YEAR : ";
			date->year = GetNumber(4);
			if (date->year > 2010 || date->year < 2024)
			{
				flag2 = true;
				break;

			}
			cout << " YOU HAVE ENTER A WRONG YEAR. PLEASE CORRECT IT " << endl;
			cout << endl;
		}
		cout << endl;

	};

	void displaymenu()
	{

		// console output 

		color(3);
		if (flag == true)
		{

			cout << endl;
			cout << "\t\t\t\t\t ----------------------------------------" << endl;
			cout << "\t\t\t\t\t |                                      |" << endl;
			cout << "\t\t\t\t\t ----------------------------------------" << endl;
			cout << "\t\t\t\t\t |      \tCITY : " << station.management.city << "           |" << endl;
			cout << "\t\t\t\t\t |      \t X : " << station.latitude << " Y : " << station.longitude << "\t\t| " << endl;
			cout << "\t\t\t\t\t |        \t"; date->dddd(); cout << "             | " << endl;
			cout << "\t\t\t\t\t |                                      |" << endl;
			cout << "\t\t\t\t\t |                                      |" << endl;
			cout << "\t\t\t\t\t |                                      |" << endl;
			cout << "\t\t\t\t\t |                                      |" << endl;
			cout << "\t\t\t\t\t |   \\  /                               |" << endl;
			cout << "\t\t\t\t\t | _ /\"\".-.      TEMPERATURE :" << *station.t->temperature << "C       |" << endl;
			cout << "\t\t\t\t\t |   \\_(   ).     HUMIDITY :   " << station.h->humidity << "%      |" << endl;
			cout << "\t\t\t\t\t |   /(___(__)     WIND : " << station.w->wind_speed << "KM/H        |" << endl;
			cout << "\t\t\t\t\t |                RAIN PERCENTAGE :" << station.r->rain_percentage << "%  |" << endl;
			cout << "\t\t\t\t\t |                RAIN  MEASURE : " << station.r->rain << "mm   |" << endl;
			cout << "\t\t\t\t\t |                                      |" << endl;
			cout << "\t\t\t\t\t |                                      |" << endl;
			cout << "\t\t\t\t\t |                                      |" << endl;
			cout << "\t\t\t\t\t |                                      |" << endl;
			cout << "\t\t\t\t\t ----------------------------------------" << endl;

			cout << endl;
			system("pause");
			system("cls");
		}

		else
			cout << " CITY NOT FOUND " << endl;

	};

	~WEATHER_FORECAST() {

		delete date;
	}

};

WEATHER_FORECAST weather;


// helping function 

void manage() {

	Date date;
	weather.station.t->get_temp();
	weather.station.w->get_windspeed();
	weather.station.h->get_humidity();
	weather.station.l->get_light();
	weather.station.r->get_raininfo();
	color(3);
	weather.displaymenu();

}

// menu function 

void menu()
{

	int choice;

	string file = "station.txt";
	string input = "infostation.txt";
	string liveFile = "utility.txt";

	do
	{
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		color(13);
		cout << "\t\t\t\t\t==========================================\n";
		cout << "\t\t\t\t\t||                                      ||\n";
		cout << "\t\t\t\t\t||                                      ||\n";
		cout << "\t\t\t\t\t||  1. TO LIVE MENU                     ||\n";
		cout << "\t\t\t\t\t||  2. TO SEE WEATHER UPDATE BY SEARCH  ||\n";
		cout << "\t\t\t\t\t||  3. TO SEARCH BY DATE                ||\n";
		cout << "\t\t\t\t\t||  4. TO STATION MANAGMENT             ||\n";
		cout << "\t\t\t\t\t||  5. TO EXIT                          ||\n";
		cout << "\t\t\t\t\t||                                      ||\n";
		cout << "\t\t\t\t\t||                                      ||\n";
		cout << "\t\t\t\t\t==========================================\n";
		cout << endl;
		cout << "ENTER A CHOICE " << endl;
		cout << endl;
		choice = GetNumber(2);
		cout << endl;

		switch (choice) {
		case 1:
		{
			process();
			do
			{
				WEATHER_FORECAST::liveMenu();
				cout << endl;
				cout << "ENTER A CHOICE " << endl;
				cout << endl;
				choice = GetNumber(2);
				cout << endl;
				switch (choice) {
				case 1:
					color(3);
					process();
					weather.station.read_livloc(liveFile);
					flag = true;
					manage();
					break;
				case 2:
					color(2);
					process();
					weather.station.searchCITY();
					weather.station.SET_ADDRESS();
					weather.station.live_loc(liveFile);
					break;
				case 3:
					cout << endl;
					color(3);
					exiting();
					break;
				default:
					cout << " INVALID CHOICE " << endl;
				}
			} while (choice != 3);

		}
		break;
		case 2:
		{
			process();
			do
			{
				color(10);
				STATION::menubysearch();
				cout << endl;
				cout << "ENTER A CHOICE " << endl;
				cout << endl;
				choice = GetNumber(2);
				cout << endl;
				switch (choice) {
				case 1:
					color(11);
					process();
					weather.station.searchCITY();
					weather.station.SET_ADDRESS();
					process();
					manage();
					break;
				case 2:
					color(13);
					process();
					weather.station.setfromarr();
					process();
					manage();
					break;
				case 3:
					color(12);
					exiting();
					break;
				default:
					cout << " INVALID INPUT \n";
				}

			} while (choice != 3);
		}
		break;
		case 3:
		{
			process();
			do
			{
				color(6);
				WEATHER_FORECAST::datemenu();
				cout << endl;
				cout << "ENTER A CHOICE " << endl;
				cout << endl;
				choice = GetNumber(2);
				cout << endl;
				switch (choice)
				{
				case 1:
					process();
					color(9);
					weather.searchBydate();
					weather.station.read_livloc(liveFile);
					weather.station.SET_ADDRESS();
					flag = true;
					process();
					manage();
					break;
				case 2:
					process();
					color(3);
					weather.searchBydate();
					weather.station.searchCITY();
					weather.station.SET_ADDRESS();
					process();
					manage();
					break;
				case 3:
					process();
					color(2);
					weather.searchBydate();
					weather.station.setfromarr();
					process();
					manage();
					break;
				case 4:
					exiting();
					break;
				default:
					cout << " INVALID CHOICE " << endl;
				}
			} while (choice != 4);
		}
		break;
		case 4:
		{
			int num1;

			process();
			do
			{
				color(6);
				STATION_MANAGMENT::menu();
				cout << endl;
				cout << "ENTER A CHOICE " << endl;
				cout << endl;
				num1 = GetNumber(2);
				cout << endl;
				switch (num1)
				{
				case 1:
					process();
					color(12);
					weather.station.management.add_station(file);
					break;
				case 2:
					process();
					color(6);
					weather.station.management.view_station(file);
					weather.station.management.delete_station(file);
					break;
				case 3:
					process();
					color(2);
					weather.station.management.view_station(file);
					weather.station.management.station_forecast(file);
					flag = true;
					process();
					manage();
					break;
				case 4:
					process();
					color(9);
					weather.station.station_info(file, input);
					process();
					color(10);
					weather.station.ReadSeninfo(input);
					break;
				case 5:
					color(14);
					exiting();
					break;
				default:
					cout << " INVALID CHOICE \n";
				}
			} while (num1 != 5);
		}
		break;

		case 5:
			color(7);
			exiting();
			break;

		default:

			cout << " INVALID CHOICE " << endl;
			break;
		}
	} while (choice != 5);


}


// startup display 

void display()
{
	blink(R"(
                    | | | |              
 _      __  _ _| || |_   __ _ __ 
 \ \ /\ / / _ \/ ` | _| '_ \ / _ \ '__|
  \ V  V /  _/ (| | || | | |  _/ |   
   \_/\_/ \__|\,|\_|| ||\_||   
                                       
                )", 11, 1); // Yellow text

	blink(R"(
    __                             _   
  / _|                           | |  
 | |_ _  _ _ __  _ _ _ _| | 
 |  / _ \| '/ _ \/ _/ ` / _| __|
 | || () | | |  _/ (| (| \__ \ |_ 
 || \_/||  \__|\_\,|_/\__|
                                                     
                )", 12, 1); // Light Blue text

	blink(R"(
                    _ _           _   _             
                   | ()         | | ()            
   _ _ _ _  _ _ | |  _ _ _| | _  _  _ __  
  / ` | ' \| '_ \| | |/ _/ _` | _| |/ _ \| '_ \ 
 | (| | |) | |) | | | (| (| | || | (_) | | | |
  \_,| ._/| ./|||\_\,|\_||\__/|| |_|
       | |   | |                                    
       ||   ||                                    
                )", 14, 1); // Light Yellow text

	// Display the full body for 2 seconds
	centerText(R"(
                    | | | |              
 _      __  _ _| || |_   __ _ __ 
 \ \ /\ / / _ \/ ` | _| '_ \ / _ \ '__|
  \ V  V /  _/ (| | || | | |  _/ |   
   \_/\_/ \__|\,|\_|| ||\_||   
                                       
                )", 11); // Yellow text

	centerText(R"(
    __                             _   
  / _|                           | |  
 | |_ _  _ _ __  _ _ _ _| | 
 |  / _ \| '/ _ \/ _/ ` / _| __|
 | || () | | |  _/ (| (| \__ \ |_ 
 || \_/||  \__|\_\,|_/\__|
                                                     
                )", 12); // Light Blue text

	centerText(R"(
                    _ _           _   _             
                   | ()         | | ()            
   _ _ _ _  _ _ | |  _ _ _| | _  _  _ __  
  / ` | ' \| '_ \| | |/ _/ _` | _| |/ _ \| '_ \ 
 | (| | |) | |) | | | (| (| | || | (_) | | | |
  \_,| ._/| ./|||\_\,|\_||\__/|| |_|
       | |   | |                                    
       ||   ||                                    
                )", 14); // Light Yellow text

	string made = "  Made by Rana Faizan Ali ";
	cout << "\t\t\t\t\t\t\t\t\t\t";
	color(10);
	for (auto& c : made)
	{
		cout << c;
		Sleep(100);
	}
	this_thread::sleep_for(chrono::seconds(2));

	system("cls");
}

// main function 

int main()
{

	srand(time(0));


	display();

	color(13);

	menu();

	color(7);
	return 0;

}