// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len; ++i) {
    for (int j = i + 1; j < len; ++j) {
      if (arr[i] + arr[j] == value) {
        counter++;
      }
    }
  }
  return counter;
}
int countPairs2(int *arr, int len, int value) {
  int counter = 0;
  int upper = len - 1;
  while (upper > 0 && arr[upper] > value) {
    upper--;
  }
  for (int min = 0; min < len; min++) {
    for (int max = upper;
      max > min; max--) {
        if (arr[min] + arr[max] == value) {
          counter++;
        }
      }
  }
  return counter;
}

int search(int* arr, int start,
int end, int key, bool findFirst) {
  int found = -1;
  while (start <= end) {
    int mid = start + (end - start) / 2;
    if (arr[mid] == key) {
      found = mid;
      if (findFirst) {
        end = mid - 1;
      } else {
        start = mid + 1;
      }
    } else if (arr[mid] < key) {
      start = mid + 1;
    } else {
      end = mid - 1;
    }
  }
  return found;
}

int countPairs3(int *arr, int len, int value) {
  int counter = 0;
  for (int i = 0; i < len; i++) {
    int difV = value - arr[i];
    int first = search(arr, i + 1,
    len - 1, difV, true);
    if (first != -1) {
      int last = search(arr, i + 1,
      len - 1, difV, false);
      counter += (last - first + 1);
    }
  }
  return counter;
}
