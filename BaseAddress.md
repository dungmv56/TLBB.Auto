https://ohaynhi.wordpress.com/2013/08/28/base-address-tlbb-cap-nhat-thuong-xuyen/

## Cập nhật ngày 15/09/2013

1. Mục tiêu (target):   base address: [0x84AD18,0x0,0xC,0x64]

2. Máu hiện tại của nhân vật:  [0x87C374,0xC,0x1DC,0x4,0x241C]

3. Máu max của nhân vật:  [0x87C374,0xC,0x1DC,0x4,0x2490]

4. Khí max của nhân vật:  [0x87C374,0xC,0x1DC,0x4,0x2494]

5. Khí hiện tại của nhân vật: [0x87C374,0xC,0x1DC,0x4,0x2420]

Thu thập thêm từ LanPhong.Net:

6. Tên nhân vật:  [0x87C374,0xC,0x1DC,0x4,0x34]

7. ID pet:  0x870574 [0x5c]

8. Máu max Pet: 0x870574 [0x4f71c, 0x48 + $petid*0x144]

9. Máu hiện tại Pet: 0x870574 [0x4f71c, 0x44 + $petid*0x144]

10. Máu của quái thường (không phải boss): 0x84ad18 [0x0,0xc,0x60,0x1c,0x10,0x1c,0x8,0x1c,0x0,0x2b0] quái chết máu = 0

* Lưu ý danh cho 10 – Máu quái:

Khi mục tiêu là boss hoặc mục tiêu chạy ra ngoài tầm nhìn thì target vẫn =1 máu không thay đổi, ta dùng 1 biến đếm từ 1.. đến .. 10 đếm các lần tấn công nếu quá 10 lần mà máu ko tụt thì chuyển mục tiêu – cách này sẽ tránh nhân vật đứng yên khi rơi vào các trường hợp đặc biệt trên.