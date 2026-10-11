// A A[0] işaret eder o da A[0][0] işaret eder biz bu adresi alıp ondan hareket ederiz 
// A[i][j] == *(*(A + i) + j) şeklinde
// Yani [][] syntax'ı aslında pointer arithmetic + dereference'ın daha okunabilir hali.
// bunlar bellekte A[0][0],A[0][1],A[0][2],A[1][0],A[1][1] şeklinde yan yana duruyor
// c/c++ böyle dizilir yani row major olarak ama column mjor oldugu dillerde var yani A[0][0], a[1][0] gibi
/*
Çünkü bellekte yan yana duran elemanlara erişmek daha hızlıdır. C++ row-major kullandığı için şu daha cache-friendly:
for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
        cout << A[i][j];

Çünkü bellekte de zaten satır satır gidiyor.
Ama şöyle dolaşırsan:
for (int j = 0; j < cols; j++)
    for (int i = 0; i < rows; i++)
        cout << A[i][j];

sütun sütun atlarsın; bellekte ardışık gitmezsin. Büyük arraylerde bu daha yavaş olabilir.
*/