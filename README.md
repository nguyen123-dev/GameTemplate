# GameTemplate (Visual Studio 2022, C++ / Direct3D 10)

Project template rút ra từ `dungdna2000/gamedev-intro-tutorials` -> `05-SceneManager`.
Kiến trúc, quy tắc đặt tên và boilerplate: xem `docs/Architecture_Boilerplate_Guide.md`.

## Mở & chạy
1. Mở `GameTemplate.sln` bằng Visual Studio 2022 (workload **Desktop development with C++**, toolset v143, Windows SDK 10).
2. Chuột phải Solution -> **Restore NuGet Packages** (gói `Microsoft.DXSDK.D3DX 9.29.952.8`, nằm trong `packages.config`).
   Nếu lỗi "missing NuGet package": *Tools > NuGet Package Manager > Package Manager Console* -> `Update-Package -reinstall`.
3. Chọn cấu hình `Debug | x64` (hoặc `x86`) -> **F5**.
4. Điều khiển: ← → đi, `A` giữ để chạy, `S` nhảy, ↓ ngồi, `1`/`2` đổi level small/big, `0` die.
   Đi vào vùng portal để sang scene khác.

Working directory của debugger đã đặt là `$(ProjectDir)` để đọc `mario-sample.txt`, `*.txt` và `textures\`.

## Việc thường làm
- Thêm object / scene / animation / state: xem Mục 6 trong `docs/Architecture_Boilerplate_Guide.md`.
- Đổi scene khởi đầu: `GameTemplate/mario-sample.txt` -> `[SETTINGS] start`.
