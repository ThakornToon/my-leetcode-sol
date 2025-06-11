int comp(const void* a,const void* b) {
    return *(char*)a-*(char*)b;
}
bool isAnagram(char* s, char* t) {
    char c=0;
    qsort(s,strlen(s),sizeof(char),comp);
    qsort(t,strlen(t),sizeof(char),comp);
    c=strcmp(s,t);
    if(c)
    {
        return c==0;
    }
    return c==0;
}