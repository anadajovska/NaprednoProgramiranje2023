#include <iostream>
using namespace std;
  
// funkcija za natrupuvanje
void heapify(int arr[], int n, int root)
{
   int largest = root; // najgolemiot element - root
   int l = 2*root + 1; // l - left, r - right
   int r = 2*root + 2; 
   
   if (l < n && arr[l] > arr[largest])
   largest = l;
    
   if (r < n && arr[r] > arr[largest])
   largest = r;

   if (largest != root)
      {
      swap(arr[root], arr[largest]);
      heapify(arr, n, largest);
      }
}

//implementiranje na Heap sortiranje
void heapSort(int arr[], int n)
{
   
   // gradenje na kupot
   for (int i = n / 2 - 1; i >= 0; i--)
   heapify(arr, n, i);
   // vadenje na elementi od kupot eden po eden
   for (int i=n-1; i>=0; i--)
   {
      // premestuvanje na momentalniot koren na krajot
      swap(arr[0], arr[i]);
  	// povtorno povikuvanje na funkcijata heapify na reduciraniot kup	
      heapify(arr, i, 0);
   }
}

// pecatenje na sortiranata niza
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << (char)arr[i] << " ";
   cout << "\n";
}
// glavna programa
int main()
{
   string str = "Ana Dajovska INKI927";
   int heap_arr[str.length()];
   // se vnesuvaat ascii kodovite na karakterite od stringot str vo niza heap_arr[]
	for(int i=0; i<str.length(); i++)
	{
		char x = str.at(i);
		heap_arr[i] = (int)x;
	}
	
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Vnesen string"<<endl;
   displayArray(heap_arr,n);
  
   // sortiranje na nizata
   heapSort(heap_arr, n);
  
   cout << "Sortiran string(niza)"<<endl;
   displayArray(heap_arr, n);
}
