#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

typedef long long ll;

int main() {

    double temperature, humidity;
    cin >> temperature >> humidity;

    map<char, double> tempWeights, humidityWeights;

    if (temperature >= 0 && temperature <= 10) {
        tempWeights['c'] = 1.0;
        tempWeights['w'] = 0.0;
        tempWeights['h'] = 0.0;
    } else if (temperature > 10 && temperature <= 20) {
        tempWeights['c'] = (temperature - 10) / 10.0;
        tempWeights['w'] = (20 - temperature) / 10.0;
        tempWeights['h'] = 0.0;
    } else if (temperature > 20 && temperature <= 30) {
        tempWeights['c'] = 0.0;
        tempWeights['w'] = 1.0;
        tempWeights['h'] = 0.0;
    } else if (temperature > 30 && temperature <= 40) {
        tempWeights['c'] = 0.0;
        tempWeights['w'] = (temperature - 30) / 10.0;
        tempWeights['h'] = (40 - temperature) / 10.0;
    } else if (temperature > 40 && temperature <= 58) {
        tempWeights['c'] = 0.0;
        tempWeights['w'] = 0.0;
        tempWeights['h'] = 1.0;
    }

    if (humidity >= 0 && humidity <= 40) {
        humidityWeights['l'] = 1.0;
        humidityWeights['h'] = 0.0;
    } else if (humidity > 50 && humidity <= 100) {
        humidityWeights['l'] = 0.0;
        humidityWeights['h'] = 1.0;
    } else if (humidity > 40 && humidity <= 50) {
        humidityWeights['l'] = (humidity - 40) / 10.0;
        humidityWeights['h'] = (50 - humidity) / 10.0;
    }

    double highWeight = max(tempWeights['c'], humidityWeights['l']);
    double lowWeight = max(min(tempWeights['w'], humidityWeights['h']), tempWeights['h']);
    double moderateWeight = min(tempWeights['w'], humidityWeights['l']);
    double weightedTempSum = 0.0;
    double totalWeight = 0.0;

    for (int i = 15; i < 18; ++i) {
        weightedTempSum += i * lowWeight;
        totalWeight += lowWeight;
    }
    for (int i = 18; i < 22; ++i) {
        double currentWeight = max(highWeight, lowWeight);
        weightedTempSum += i * currentWeight;
        totalWeight += currentWeight;
    }
    for (int i = 22; i < 24; ++i) {
        double currentWeight = max(moderateWeight, lowWeight);
        weightedTempSum += i * currentWeight;
        totalWeight += currentWeight;
    }
    for (int i = 24; i < 28; ++i) {
        weightedTempSum += i * lowWeight;
        totalWeight += lowWeight;
    }
    for (int i = 28; i <= 30; ++i) {
        weightedTempSum += i * highWeight;
        totalWeight += highWeight;
    }

    cout << "Temperature: " << fixed << setprecision(9) << weightedTempSum / totalWeight << endl;

    return 0;
}
