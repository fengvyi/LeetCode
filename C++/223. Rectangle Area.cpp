class Solution {
public:
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int areaA = (C - A) * (D - B);
		int areaB = (G - E) * (H - F);
		if (C < E || A > G || B > H || D < F) return areaA + areaB;
		// Bottom left(I, J), Top right(K, L).
		int I = max(A, E);
		int J = max(B, F);
		int K = min(C, G);
		int L = min(D, H);
		int overlap = (K - I) * (L - J);
		return areaA + areaB - overlap;
	}
};