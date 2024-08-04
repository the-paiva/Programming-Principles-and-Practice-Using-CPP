/*Read a sequence of double values into a vector. Think of each value as
the distance between two cities along a given route. Compute and print
the total distance (the sum of all distances). Find and print the smallest
and greatest distance between two neighboring cities. Find and print the
mean distance between two neighboring cities.*/

#include <iostream>
#include <vector>
using namespace std;

//Gets a sequence of double values, adding to an array
vector<double> get_double_array(vector<double> array, int ammount){
    double temporary_value;

    for (int count = 0; count < ammount; count++){
        while (true){
            cout << "Enter the " << count + 1 << "th distance (km): ";
            cin >> temporary_value;

            if (temporary_value > 0){
                array.push_back(temporary_value);
                break;
            }

            cout << "INVALID VALUE!";
        }
    }

    return array;
}

//Gets the sum of all the values in a double array
double get_double_sum(vector<double> array, int ammount){
    double sum = 0;

    for (int count = 0; count < ammount; count++){
        sum += array[count];
    }

    return sum;
}

//Gets the smaller value of a double array
double get_double_smaller(vector<double> array, int ammount){
    double smaller_num = array[0];

    for (int count = 1; count < ammount; count++){
        if (array[count] < smaller_num){
            smaller_num = array[count];
        }
    }

    return smaller_num;
}

//Gets the larger value of a double array
double get_double_larger(vector<double> array, int ammount){
    double larger_num = array[0];

    for (int count = 1; count < ammount; count++){
        if (array[count] > larger_num){
            larger_num = array[count];
        }
    }

    return larger_num;
}

//Gets the mean of double values
double get_double_mean(int ammount, int sum){
    double mean = sum / ammount;

    return mean;
}

int main(){
    vector<double> distance(0);
    int ammount;

    cout << "\nEnter the ammount of city distances to be entered: ";
    cin >> ammount;
    cout << "\n";

    distance = get_double_array(distance, ammount);

    double sum = get_double_sum(distance, ammount);
    cout << "\nSum of the distances: " << sum << " km";

    double smaller_num = get_double_smaller(distance, ammount);
    double larger_num = get_double_larger(distance, ammount);
    cout << "\nSmaller distance: " << smaller_num << " km\nLarger distance: " << larger_num <<" km";

    double mean = get_double_mean(ammount, sum);
    cout << "\nMean distance between cities: " << mean << " km\n";

    return 0;
}
