double round(double a, int afterPoint) {
    const double eps = 1e-9;
    int TT = 1;
    while (afterPoint--) TT *= 10;
    if (fabs((a * (1.0 * TT)) - (int) (a * TT) - 0.5) > eps && (int) (a * TT * 10) % 10 >= 5)
        return ceil(a * (1.0 * TT)) / (1.0 * TT);
    else
        return floor(a * (1.0 * TT)) / (1.0 * TT);
}
