#include <iostream>
#include<vector>
using namespace std;

/** This function performs a basic smoothing of * array 'in', writing the result into 'out'.
* Both arrays are assumed to have length N, and * it is assumed that h>=0. For each i, out[i]
* will be the average of in[k] over all k that
* satisfy i-h<=k<=i+h and 0<=k<=N-1. */ 


class Smooth {
  public:

     Smooth(const double* in, double* out, int N, int h)
    {
        // for loop to iterate through calculation of each output value
        for (int i=0;i < N; i++)
        {
            // initialisation of values used to calculate average
            double sum = 0;
            int count = 0;

            // for loop which sums required values and counts them 
            //Max() and min() is used to reduce complexity by disregarding unnecessary iterations
            for (int k=max(i-h,0); k <= min(i+h,N-1) ; k++)
            {
                sum +=in[k];
                count++;
            }

            // Calculating average
            out[i]= sum /count;
        }

    };
};
int main() {
    vector<double> inputArray = {1.0, 2.0, 3.0, 4.0, 5.0,6};

    // Assuming you want to store the smoothed values in an array
    int N = sizeof(inputArray);
    int h = 3;
    double out[N];
    

    // Create an instance of the Smooth class
    Smooth mySmooth(inputArray.data(), out, N, h);

    // Print the smoothed array
    cout << "Smoothed Array: ";
    for (int i = 0; i < N; i++) {
        cout << out[i] << " ";
    }

    return 0;
}
