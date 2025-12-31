#include <iostream>
using namespace std;

int quickselect(vector<int>& A, vector<int>& B, int Al, int Ar, int Bl, int Br, int k) {
	int Amid = (Al + Ar) / 2;
	int Bmid = (Bl + Br) / 2;

	if (Al > Ar) return B[k - Al];
	if (Bl > Br) return A[k - Bl];

	if (Amid + Bmid < k) {
			if (A[Amid] <= B[Bmid]) {
					return quickselect(A, B, Amid + 1, Ar, Bl, Br, k); // discard A_left
			} else {
					return quickselect(A, B, Al, Ar, Bmid + 1, Br, k); // discard B_left
			}
	} else {
			if (A[Amid] <= B[Bmid]) {
					return quickselect(A, B, Al, Ar, Bl, Bmid - 1, k); // discard B_right 
			} else {
					return quickselect(A, B, Al, Amid - 1, Bl, Br, k); // discard A_right 
			}
	}
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	int An = nums1.size();
	int Bn = nums2.size();
	if((An + Bn) % 2 == 1) return quickselect(nums1, nums2, 0, An - 1, 0, Bn - 1, (An + Bn)/2);
	else {
		int lres = quickselect(nums1, nums2, 0, An - 1, 0, Bn - 1, (An + Bn)/2);
		int rres = quickselect(nums1, nums2, 0, An - 1, 0, Bn - 1, (An + Bn)/2 - 1);
		return (lres + rres) / 2.0;
	}
}

int main() {
	int N; cin >> N;
	vector<int> A(N);
	for(int i = 0; i<N; i++){
		cin >> A[i];
	}
	int M; cin >> M;
	vector<int> B(M);
	for(int i = 0; i<M; i++){
		cin >> B[i];
	}
	cout << findMedianSortedArrays(A, B) << endl;
}
