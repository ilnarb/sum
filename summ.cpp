double sum1(std::vector& v)
{    
    if (v.empty()) {
        return 0.0;
    }
    for(size_t i = 0; i < v.size() - 1; ++i) {
        std::sort(v.begin()+i, v.end());
        v[i+1] += v[i];
    }
    return v.back();
}
 
double sum2(std::vector& v)
{    
    if (v.empty()) {
        return 0.0;
    }
    for(size_t i = 0; i < v.size() - 1; ++i) {
        std::partial_sort(v.begin() + i, v.begin() + i + 2, v.end());
        v[i+1] += v[i];
    }
    return v.back();
}
 
double sum3(std::vector& v)
{    
    std::multiset set(v.begin(), v.end());
    while (set.size() > 1) {
        std::multiset::const_iterator itA = set.begin();
        std::multiset::const_iterator itB = ++set.begin();
        double c = *itA + *itB;
        set.erase(itA, itB);        
        set.insert(c);
    }
    return !set.empty() ? *set.begin() : 0.0;
}
