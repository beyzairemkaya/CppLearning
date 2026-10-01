# What is in week5
| Kategori    | Kafandaki karşılığı                            |
| ----------- | ---------------------------------------------- |
| **lvalue**  | Kimliği olan normal nesne: `x`                 |
| **prvalue** | Hesaplanan/geçici değer: `5`, `x + 2`          |
| **xvalue**  | Kaynakları taşınabilecek nesne: `std::move(x)` |
| **glvalue** | `lvalue + xvalue`                              |
| **rvalue**  | `prvalue + xvalue`                             |