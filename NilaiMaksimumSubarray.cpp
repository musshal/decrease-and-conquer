/* File     : NilaiMaksimumSubArray.cpp */
/* Nama     : Musthafa Kamal Faishal */
/* NIM      : 24060118120042 */
/* Deskripsi: Menemukan subarray bersebelahan (berisi setidaknya satu angka) yang memiliki */
/*            jumlah terbesar dan kembalikan hasilnya */

/* file header */
#include <iostream>
using namespace std;

/* fungsi untuk mencari elemen tertinggi dari dua integer */
int max(int a, int b) {
  /* kamus lokal */

  /* algoritma */
	return (a > b) ? a : b;
}

/* fungsi untuk mencari jumlah maksimum dari subarray */
int MaxCrossingSum(int arr[], int low, int mid, int high) {
	/* kamus lokal */
	int sum = 0;
	int leftpartsum = -1;
  int rightpartsum;
  int i; // iterator

  /* algoritma */
  // menyertakan elemen yang memiliki nilai indeks <= nilai tengah
	for (i = mid; i >= low; i--) {
		sum = sum + arr[i];

		if (sum > leftpartsum)
			leftpartsum = sum;
	}

	// menyertakan elemen yang memiliki nilai indeks tengah lebih besar
	sum = 0;
	rightpartsum = -1;

	for (i = mid + 1; i <= high; i++) {
		sum = sum + arr[i];

		if (sum > rightpartsum)
			rightpartsum = sum;
    }

	// mengembalikan jumlah elemen di kiri dan kanan tengah
	return leftpartsum + rightpartsum;
}

/* fungsi untuk mengembalikan jumlah jumlah subarray maksimum */
int MaxSubArraySum(int arr[], int low, int high) {
  /* kamus lokal */
  int mid;

  /* algoritma */
	// jika indeks rendah == indeks tinggi h, maka subarray hanya berisi satu elemen
	if (low == high)
		return arr[low];
 
	// jika tidak, temukan indeks tengah dan lanjutkan
	mid = (low + high)/2;
 
	// jumlah maksimum subarray dapat berupa bagian kiri, bagian kanan atau elemen penutup dari kedua bagian
	return max(max(MaxSubArraySum(arr, low, mid), MaxSubArraySum(arr, mid+1, high)), MaxCrossingSum(arr, low, mid, high));
}

/* driver */
int main() {
  /* kamus */
  int N; // panjang array
  int array[N]; // wadah elemen array
  int i; // iterator

  /* algoritma */
  cin >> N; // menerima masukan panjang array

  // inisialisasi elemen-elemen array
  for (i = 0; i < N; i++) {
    cin >> array[i];
  }

  // menampilkan nilai maksimum dari subarray
  cout << MaxSubArraySum(array, 0, N-1);

  return 0; 
}