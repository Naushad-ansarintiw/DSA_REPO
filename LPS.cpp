void computeLPS(string pattern, vector<int> &LPS, int M) {
  int len = 0; // length of the previous longest prefix & suffix 
  LPS[0] = 0;
  int i=1; 
  while(i<M) {
    if(pat[i] == pat[j]) {
      len++;
      LPS[i] = len;
      i++;
    } else {
      if(len != 0 ) {
          len = LPS[len-1];
      } else {
          LPS[i] = 0;
          i++;
      }
    }
  }
}
