#include <stdexcept>

class AList: public List{
    public:
        int* listArray;
        static const DEFAULT_SİZE=10;
        int max_size;
        int listSize;
        int curr;
         AList(int size = DEFAULT_SIZE)
        : listSize(0), curr(0)
        {
            maxSize = size;
            listArray = new ListItemType[size];
        }

        ~AList() {
            delete[] listArray;
        }
        void  clear(){
            // public altına yazmayı unutma yoks class default private oldugu için dışardan erişemezsin
            listSize=curr=0;
        }
        bool insert(const int& it ){
            // insert it to curr posion
            if (listSize>=max_size) return false;
            for (int i=listSize; i>curr;i--){
                listArray[i]=listArray[i-1];
            }
            listArray[curr]=it;
            listSize++;
            return true;
        }
        bool append(const int& it){
            if (listSize>=max_size) return false;
            listArray[listSize++]=it;
            // önce atıyorum 4. indexe a yı atadı sonra listsize i 5 boyutune gatirdi dikkat et
            return true;

        }
        int remove(){
            if (curr<0||curr>=list_size) throw std::out_of_range("Invalid position");
            int removingItem=listArray[i];
            for(int i=curr;i<list_size-1;i--){
                listArray[i]=listArray[i+1];
            }
            listSize--;
        }
        bool moveToPos(int pos) {
        if ((pos < 0) || (pos > listSize))
            return false;

        curr = pos;
        return true;
        }
        bool isAtEnd() {
            return curr == listSize;
        } // son elamnda değil listenin sounuda mı diye bakıyor çünkü mesela son elemanda olsak insert yapabiliriz ama listenin 
        // sonundaysak yaapmayız
}