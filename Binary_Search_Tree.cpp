#include <iostream>
using namespace std;

// Membuat class Node sebagai representasi setiap simpul (node) dalam pohon biner
class Node {

    // Akses modifier public agar atribut dan method bisa diakses dari luar class
public:
    string info;        // Menyimpan data/nilai yang ada di dalam node
    Node* leftChild;    // Pointer yang menunjuk ke anak kiri node
    Node* rightChild;   // Pointer yang menunjuk ke anak kanan node

    // Constructor class Node: dipanggil saat membuat object Node baru
    // Parameter: i = nilai data, l = pointer anak kiri, r = pointer anak kanan
    Node(string i, Node* l, Node* r) 
    {
        info = i;           // Mengisi atribut info dengan nilai parameter i
        leftChild = l;      // Mengisi atribut leftChild dengan pointer parameter l
        rightChild = r;     // Mengisi atribut rightChild dengan pointer parameter r
    }
};

// Membuat class BinaryTree sebagai representasi struktur pohon biner secara keseluruhan
class BinaryTree {

public:
    Node* ROOT;     // Pointer ke node akar (root) dari pohon biner

    // Constructor class BinaryTree: dipanggil saat membuat object BinaryTree baru
    BinaryTree() 
    {
        ROOT = nullptr;     // Inisialisasi ROOT dengan nullptr, artinya pohon masih kosong
    }

    // Prosedur insert: menambahkan elemen baru ke dalam pohon biner
    void insert(string element) 
    {
        // Membuat node baru dengan nilai element, anak kiri & kanan masih nullptr
        Node* newNode = new Node(element, nullptr, nullptr);
        newNode->info = element;            // Mengisi info node baru dengan nilai element
        newNode->leftChild = nullptr;       // Anak kiri node baru diset nullptr
        newNode->rightChild = nullptr;      // Anak kanan node baru diset nullptr

        Node* parent = nullptr;         // Pointer untuk menyimpan node induk (parent) dari posisi yang ditemukan
        Node* currentNode = nullptr;    // Pointer untuk menyimpan node saat ini dalam proses pencarian

        // Memanggil fungsi search untuk menemukan posisi yang tepat dalam pohon
        search(element, parent, currentNode);

        // Jika parent masih NULL, berarti pohon masih kosong → node baru menjadi ROOT
        if (parent == NULL)
        {
            ROOT = newNode;     // Node baru langsung dijadikan root
            return;             // Keluar dari fungsi insert
        }

        // Jika nilai element lebih kecil dari nilai parent, masukkan ke anak kiri
        if (element < parent->info)
        {
            parent->leftChild = newNode;    // Node baru ditempatkan sebagai anak kiri parent
        }

        // Jika nilai element lebih besar dari nilai parent, masukkan ke anak kanan
        else if (element > parent->info)
        {
            parent->rightChild = newNode;   // Node baru ditempatkan sebagai anak kanan parent
        }
    }

    // Fungsi search: mencari posisi yang sesuai untuk element dalam pohon
    // parent dan currentNode dikirim by reference (&) agar nilainya bisa diubah langsung
    void search(string element, Node *&parent, Node *&currentNode)
    {
        currentNode = ROOT;     // Mulai pencarian dari node ROOT
        parent = NULL;          // Parent diinisialisasi NULL (belum ada parent)

        // Loop selama currentNode tidak NULL dan info-nya tidak sama dengan element
        while((currentNode != NULL) &&
            (currentNode->info != element))
            {
                parent = currentNode;   // Simpan currentNode sebagai parent sebelum bergerak

                // Jika element lebih kecil, geser ke anak kiri
                if (element < currentNode->info)
                    currentNode = currentNode->leftChild;
                else
                    // Jika element lebih besar atau sama, geser ke anak kanan
                    currentNode = currentNode->rightChild;
        }
    } 

    // Prosedur inorder: menelusuri pohon dengan urutan Kiri → Root → Kanan
    void inorder(Node *ptr)
    {
        // Jika ROOT kosong, tampilkan pesan dan hentikan
        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }

        // Rekursi: selama node yang ditunjuk ptr tidak NULL
        if (ptr != NULL)
        {
            inorder(ptr->leftChild);    // Kunjungi anak kiri terlebih dahulu (rekursif)
            cout << ptr->info << " ";   // Cetak nilai node saat ini
            inorder(ptr->rightChild);   // Kunjungi anak kanan setelah cetak (rekursif)
        }
    }

    // Prosedur preorder: menelusuri pohon dengan urutan Root → Kiri → Kanan
    void preorder(Node *ptr)
    {
        // Jika ROOT kosong, tampilkan pesan dan hentikan
        if (ROOT == NULL)
        {
            cout <<"Tree is empty" <<  endl;
            return;
        }

        // Rekursi: selama node yang ditunjuk ptr tidak NULL
        if (ptr != NULL)
        {
            cout << ptr->info << " ";   // Cetak nilai node saat ini terlebih dahulu
            preorder(ptr->leftChild);   // Kunjungi anak kiri (rekursif)
            preorder(ptr->rightChild);  // Kunjungi anak kanan (rekursif)
        }
    }

    // Prosedur postorder: menelusuri pohon dengan urutan Kiri → Kanan → Root
    void postorder(Node *ptr)
    {
        // Jika ROOT kosong, tampilkan pesan dan hentikan
        if (ROOT == NULL)
        {
            cout << "Tree is empty" << endl;
            return;
        }

        // Rekursi: selama node yang ditunjuk ptr tidak NULL
        if (ptr != NULL)
        {
            postorder(ptr->leftChild);  // Kunjungi anak kiri terlebih dahulu (rekursif)
            postorder(ptr->rightChild); // Kunjungi anak kanan setelah kiri (rekursif)
            cout << ptr->info << " ";   // Cetak nilai node saat ini paling terakhir
        }
    }

};

// Fungsi utama: titik awal eksekusi program
int main()
{
    BinaryTree obj;         // Membuat object BinaryTree bernama obj, ROOT = nullptr
    while (true)            // Loop tak terbatas untuk menampilkan menu berulang kali
    {
        // Menampilkan menu pilihan ke layar
        cout << "\nMenu" << endl;
        cout << "1. implement insert operation" << endl;
        cout << "2. perform inorder traversal" << endl;
        cout << "3. perform preorder traversal" << endl;
        cout << "4. perform postorder traversal" << endl;
        cout << "5. exit" << endl;
        cout << "\nEnter your choice (1-5): ";

        char ch;        // Variabel untuk menyimpan pilihan menu dari user
        cin >> ch;      // Membaca input karakter dari user

        cout << endl;   // Mencetak baris kosong untuk estetika tampilan
        
        // Percabangan berdasarkan pilihan user
        switch (ch)
        {
        case '1':
        {
            cout << "Enter a word: ";
            string word;        // Variabel untuk menyimpan kata yang diinput user
            cin >> word;        // Membaca input kata dari user
            obj.insert(word);   // Memanggil fungsi insert untuk memasukkan kata ke pohon
            break;              // Keluar dari switch
        }
        case '2':
        {
            obj.inorder(obj.ROOT);  // Memanggil inorder traversal dimulai dari ROOT
            break;
        }
        case '3':
        {
            obj.preorder(obj.ROOT); // Memanggil preorder traversal dimulai dari ROOT
            break;
        }
        
        case '4':
        {
            obj.postorder(obj.ROOT);    // Memanggil postorder traversal dimulai dari ROOT
            break;
        }
        case '5':
            return 0;   // Mengakhiri program dengan return 0 (sukses)
        
        default:
        {
            cout << "Invalid option" << endl;   // Pesan error jika pilihan tidak valid
            break;
        }
        }
    }
    return 0;   // Return 0 di akhir fungsi main (standar C++)
}