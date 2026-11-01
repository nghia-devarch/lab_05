#include <iostream>
#include <iomanip>

#include "1d_array/array_1d_utils.h"
#include "2d_array/array_2d_utils.h"

using namespace std;

const int MAX_SIZE = 1000;

int main() {
    int arr[MAX_SIZE];
    int n = 0;

    cout << "====================================================\n";
    cout << "         CHUONG TRINH CHAY CAC HAM MANG 1 CHIEU     \n";
    cout << "====================================================\n\n";

    // 1. Nhập và in mảng
    cout << "--- 1. NHAP VA XUAT MANG ---\n";
    cout << "Nhap so luong phan tu n: ";
    if (!(cin >> n) || n <= 0 || n >= MAX_SIZE) {
        cout << "So luong phan tu khong hop le!\n";
        return 1;
    }

    cout << "Nhap " << n << " phan tu cua mang: ";
    input_array(arr, n);

    cout << "Mang vua nhap: ";
    print_array(arr, n);
    cout << "\n\n";

    // 2. Tính tổng và tích các phần tử
    cout << "--- 2. TINH TONG VA TICH MANG ---\n";
    long long sum = compute_array(arr, n, '+');
    long long prod = compute_array(arr, n, '*');
    cout << "Tong cac phan tu: " << sum << "\n";
    cout << "Tich cac phan tu: " << prod << "\n\n";

    // 3. Tính giá trị trung bình cộng
    cout << "--- 3. TINH TRUNG BINH CONG (MEAN) ---\n";
    cout << "Gia tri trung binh: " << fixed << setprecision(2) << compute_mean(arr, n) << "\n\n";

    // 4. Tìm kiếm phần tử
    cout << "--- 4. TIM KIEM PHAN TU ---\n";
    int val_search;
    cout << "Nhap gia tri can tim: ";
    cin >> val_search;
    int found_idx = search(arr, n, val_search);
    if (found_idx != -1) {
        cout << "Tim thay " << val_search << " tai chi so (index): " << found_idx << "\n\n";
    } else {
        cout << "Khong tim thay " << val_search << " trong mang!\n\n";
    }

    // 5. Thêm phần tử tại vị trí index
    cout << "--- 5. THEM PHAN TU TAI CHI SO (INDEX) ---\n";
    int val_add, idx_add;
    cout << "Nhap gia tri can them: ";
    cin >> val_add;
    cout << "Nhap vi tri index can them (0 den " << n << "): ";
    cin >> idx_add;
    if (add_at_index(arr, n, val_add, idx_add)) {
        cout << "Them thanh cong!\n";
        cout << "Mang sau khi them: ";
        print_array(arr, n);
        cout << "\n\n";
    } else {
        cout << "Them that bai! Vi tri index khong hop le.\n\n";
    }

    // 6. Xóa phần tử tại vị trí index
    cout << "--- 6. XOA PHAN TU TAI CHI SO (INDEX) ---\n";
    int idx_remove;
    cout << "Nhap vi tri index can xoa (0 den " << n - 1 << "): ";
    cin >> idx_remove;
    if (remove_at_index(arr, n, idx_remove)) {
        cout << "Xoa thanh cong!\n";
        cout << "Mang sau khi xoa: ";
        print_array(arr, n);
        cout << "\n\n";
    } else {
        cout << "Xoa that bai! Vi tri index khong hop le.\n\n";
    }

    // 7. Tìm max và min
    cout << "--- 7. TIM GIA TRI LON NHAT VA NHO NHAT ---\n";
    int max_val = get_max_min(arr, n, true);
    int min_val = get_max_min(arr, n, false);
    cout << "Gia tri lon nhat (Max): " << max_val << "\n";
    cout << "Gia tri nho nhat (Min): " << min_val << "\n\n";

    // 8. Sắp xếp mảng
    cout << "--- 8. SAP XEP MANG ---\n";
    cout << "Sap xep tang dan (sort_ascending): ";
    sort_ascending(arr, n);
    print_array(arr, n);
    cout << "\n";

    cout << "Sap xep giam dan (sort_descending): ";
    sort_descending(arr, n);
    print_array(arr, n);
    cout << "\n";

    cout << "Sap xep bang ham sort(arr, n, true) (tang dan): ";
    sort(arr, n, true);
    print_array(arr, n);
    cout << "\n\n";

    // 9. Tính trung vị (median)
    cout << "--- 9. TINH TRUNG VI (MEDIAN) ---\n";
    cout << "Gia tri trung vi (median): " << fixed << setprecision(2) << compute_median(arr, n) << "\n";
    cout << "Mang sau khi tinh median: ";
    print_array(arr, n);
    cout << "\n\n";

    cout << "====================================================\n";
    cout << "                 HOAN THANH KIEM TRA                \n";
    cout << "====================================================\n";

    return 0;
}
