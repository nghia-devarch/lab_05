#include <iostream>
#include <iomanip>

#include "1d_array/array_1d_utils.h"
#include "2d_array/array_2d_utils.h"

using namespace std;

const int MAX_1D_SIZE = 1000;

void run_1d_array() {
    int arr[MAX_1D_SIZE];
    int n = 0;

    cout << "\n====================================================\n";
    cout << "         CHUONG TRINH CHAY CAC HAM MANG 1 CHIEU     \n";
    cout << "====================================================\n\n";

    // 1. Nhập và in mảng
    cout << "--- 1. NHAP VA XUAT MANG ---\n";
    cout << "Nhap so luong phan tu n: ";
    if (!(cin >> n) || n <= 0 || n >= MAX_1D_SIZE) {
        cout << "So luong phan tu khong hop le!\n";
        return;
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
    cout << "              HOAN THANH MANG 1 CHIEU               \n";
    cout << "====================================================\n\n";
}

void run_2d_array() {
    int arr_2d[MAX_ROWS][MAX_COLS];
    int rows = 0, cols = 0;

    cout << "\n====================================================\n";
    cout << "         CHUONG TRINH CHAY CAC HAM MANG 2 CHIEU     \n";
    cout << "====================================================\n\n";

    // 1. Nhập số hàng, số cột và mảng 2 chiều
    cout << "--- 1. NHAP VA XUAT MANG 2 CHIEU ---\n";
    cout << "Nhap so hang (rows): ";
    cin >> rows;
    cout << "Nhap so cot (cols): ";
    cin >> cols;

    if (rows <= 0 || rows > MAX_ROWS || cols <= 0 || cols > MAX_COLS) {
        cout << "Kich thuoc mang khong hop le!\n";
        return;
    }

    cout << "Nhap " << rows * cols << " phan tu cho mang 2 chieu:\n";
    input_2d(arr_2d, rows, cols);

    cout << "Mang 2 chieu vua nhap:\n";
    print_2d(arr_2d, rows, cols);
    cout << "\n\n";

    // 2. Tính tổng và tích các phần tử trong mảng 2 chiều
    cout << "--- 2. TINH TONG VA TICH MANG 2 CHIEU ---\n";
    long long sum_2d = compute_2d(arr_2d, rows, cols, '+');
    long long prod_2d = compute_2d(arr_2d, rows, cols, '*');
    cout << "Tong cac phan tu: " << sum_2d << "\n";
    cout << "Tich cac phan tu: " << prod_2d << "\n\n";

    // 3. Tính giá trị trung bình cộng mảng 2 chiều
    cout << "--- 3. TINH TRUNG BINH CONG (MEAN) ---\n";
    cout << "Gia tri trung binh: " << fixed << setprecision(2) << compute_mean_2d(arr_2d, rows, cols) << "\n\n";

    // 4. Kiểm tra tồn tại giá trị trong mảng 2 chiều
    cout << "--- 4. KIEM TRA TON TAI PHAN TU (CHECK EXIST) ---\n";
    int val_check;
    cout << "Nhap gia tri can kiem tra: ";
    cin >> val_check;
    if (check_exist(arr_2d, rows, cols, val_check)) {
        cout << "Gia tri " << val_check << " CO ton tai trong mang 2 chieu.\n\n";
    } else {
        cout << "Gia tri " << val_check << " KHONG ton tai trong mang 2 chieu.\n\n";
    }

    // 5. Tìm giá trị lớn nhất và nhỏ nhất trong mảng 2 chiều
    cout << "--- 5. TIM GIA TRI LON NHAT VA NHO NHAT ---\n";
    int max_val = get_max_min_2d(arr_2d, rows, cols, true);
    int min_val = get_max_min_2d(arr_2d, rows, cols, false);
    cout << "Gia tri lon nhat (Max): " << max_val << "\n";
    cout << "Gia tri nho nhat (Min): " << min_val << "\n\n";

    cout << "====================================================\n";
    cout << "              HOAN THANH MANG 2 CHIEU               \n";
    cout << "====================================================\n\n";
}

int main() {
    int choice = -1;

    while (true) {
        cout << "====================================================\n";
        cout << "                   MENU CHUONG TRINH                \n";
        cout << "====================================================\n";
        cout << "1. Chay bai tap Mang 1 chieu (1D Array)\n";
        cout << "2. Chay bai tap Mang 2 chieu (2D Array)\n";
        cout << "0. Thoat chuong trinh\n";
        cout << "====================================================\n";
        cout << "Nhap lua chon cua ban (0-2): ";

        if (!(cin >> choice)) {
            cin.clear();
            string dummy;
            getline(cin, dummy);
            cout << "Lua chon khong hop le, vui long nhap lai!\n\n";
            continue;
        }

        switch (choice) {
            case 1:
                run_1d_array();
                break;
            case 2:
                run_2d_array();
                break;
            case 0:
                cout << "Tam biet!\n";
                return 0;
            default:
                cout << "Lua chon khong hop le, vui long chon lai!\n\n";
                break;
        }
    }

    return 0;
}
