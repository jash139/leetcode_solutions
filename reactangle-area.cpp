class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (C - A) * (D - B);
        int area2 = (G - E) * (H - F); 
        if (A >= G || C <= E || D <= F || B >= H)
            return area1 + area2; 
        int overlapArea = (min(G, C) - max(A, E)) * (min(D, H) - max(B, F));
        return area1 - overlapArea + area2;
    }
};
