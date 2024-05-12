#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
using namespace std;
using namespace std::chrono;

ifstream f("vector.in");
ofstream g("vector.out");
vector<int> v;
vector<int> x;
int a[100000];
void insertionSort(vector<int>& arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(vector<int>& arr)
{
    int n = arr.size();
    for (int i = 0; i < n-1; i++)
    {
        int min_index = i;
        for (int j = i+1; j < n; j++)
            if (arr[j] < arr[min_index])
                min_index = j;
        swap(arr[min_index], arr[i]);
    }
}

void bubbleSort(vector<int>& arr)
{
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n-1; i++)
    {
        swapped = false;
        for (int j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int partition(vector<int>& arr, int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high- 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}
void quickSort(vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void merge(std::vector<int> &arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    std::vector<int> L(n1), R(n2);
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
    i = 0; j = 0; k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::vector<int> &arr, int l, int r) {
    if (l < r) {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
void countingSort(std::vector<int>& arr) {
    int max = *std::max_element(arr.begin(), arr.end());
    int min = *std::min_element(arr.begin(), arr.end());
    int range = max - min + 1;
    std::vector<int> count(range), output(arr.size());
    for(int i = 0; i < arr.size(); i++)
        count[arr[i] - min]++;
    for(int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];
    for(int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }
    for(int i = 0; i < arr.size(); i++)
        arr[i] = output[i];
}

int main()
{
    int temp;
    while(f >> temp)
    {
        if(temp>0)
        v.push_back(temp);
        else
            v.push_back(temp*(-1));
    }
    x=v;
    auto start = high_resolution_clock::now();
    selectionSort(v);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Timpul de rulare pentru selectionSort: " << duration.count() << " milisecunde" << endl;
    v.clear();
    v=x;
    auto start2 = high_resolution_clock::now();
    insertionSort(v);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<milliseconds>(stop2 - start2);
    cout << "Timpul de rulare pentru sortarea prin insertie: " << duration2.count() << " milisecunde" << endl;
    v.clear();
    v=x;
    auto start3 = high_resolution_clock::now();
    bubbleSort(v);
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<milliseconds>(stop3 - start3);
    cout << "Timpul de rulare pentru bubbleSort: " << duration3.count() << " milisecunde" << endl;
    v.clear();
    v=x;
    auto start4 = high_resolution_clock::now();
    std::sort(v.begin(), v.end());
    auto stop4 = high_resolution_clock::now();
    auto duration4 = duration_cast<milliseconds>(stop4 - start4);
    cout << "Timpul de rulare pentru quickSort: " << duration4.count() << " milisecunde" << endl;
    v.clear();
    v=x;
    auto start5 = high_resolution_clock::now();
    mergeSort(v,0,v.size()-1);
    auto stop5 = high_resolution_clock::now();
    auto duration5 = duration_cast<milliseconds>(stop5 - start5);
    cout << "Timpul de rulare pentru mergeSort: " << duration5.count() << " milisecunde" << endl;
    v.clear();
    v=x;
    auto start6 = high_resolution_clock::now();
    heapSort(v);
    auto stop6 = high_resolution_clock::now();
    auto duration6 = duration_cast<milliseconds>(stop6 - start6);
    cout << "Timpul de rulare pentru heapSort: " << duration6.count() << " milisecunde" << endl;
     v.clear();
    v=x;
    auto start7 = high_resolution_clock::now();
    countingSort(v);
    auto stop7 = high_resolution_clock::now();
    auto duration7 = duration_cast<milliseconds>(stop7 - start7);
    cout << "Timpul de rulare pentru countingSort: " << duration7.count() << " milisecunde" << endl;
    int j=0;
    for(int i=0; i<v.size(); i++)
    {
        if(j==20)
        {
            g<<endl;
            j=0;
        }
        j++;
        g<<v[i]<<' ';
    }
    f.close();
    g.close();
    return 0;
}
