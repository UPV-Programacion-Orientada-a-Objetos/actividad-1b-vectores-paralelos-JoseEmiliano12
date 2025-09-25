#include <iostream>
#include <string>
using namespace std; 

const int PRODUCTOS_MAX = 100; // Tamaño del inventario 

int codigo [PRODUCTOS_MAX];
std::string nombres [PRODUCTOS_MAX];
int stock [PRODUCTOS_MAX];
float precios [PRODUCTOS_MAX];

int TotaldeProductos = 0;

void InventarioDeProductos(){
    //Producto 1 Martillo de bola
    codigo[0] = 101;
    nombres[0] = "Martillo de bola";
    stock[0] = 50;
    precios[0] = 150.00;

    //Producto 2 Destornillador
    codigo[1] = 102;
    nombres[1] = "Destornillador";
    stock[1] = 120;
    precios[1] = 50.00;

    //Producto 3 Cinta Metrica
    codigo[2] = 103;
    nombres[2] = "Cinta Metrica";
    stock[2] = 75;
    precios[2] = 30.00;

    //Producto 4 Llave inglesa 
    codigo[3] = 104;
    nombres[3] = "Llave inglesa";
    stock[3] = 45;
    precios[3] = 80.00;

    //Producto 5 Taladro inalambrico
    codigo[4] = 105;
    nombres[4] = "Taladro inalambrico";
    stock[4] = 30;
    precios[4] = 100.00;

    TotaldeProductos = 5;
}

void consultarProducto() {   // hace la consulta por el id (codigo)
    int cod;
    cout << "Codigo del producto: ";
    cin >> cod;
    for (int i = 0; i < TotaldeProductos; i++) {
        if (codigo[i] == cod) {
            cout << "Codigo: " << codigo[i] << "\n";
            cout << "Nombre: " << nombres[i] << "\n";
            cout << "Stock: " << stock[i] << "\n";
            cout << "Precio: $" << precios[i] << "\n";
            return;
        }
    }
    cout << "No se encontro el producto\n";
}

// suma o resta el stock agrega o quita productos
void actualizarInventario() {
    int cod, cant;
    cout << "Codigo del producto: ";
    cin >> cod;
    cout << "Cantidad a modificar (+ suma, - resta): ";
    cin >> cant;

    for (int i = 0; i < TotaldeProductos; i++) {
        if (codigo[i] == cod) {
            if (stock[i] + cant >= 0) {
                stock[i] = stock[i] + cant;
                cout << "Nuevo stock: " << stock[i] << "\n";
            } else {
                cout << "Stock insuficiente\n";
            }
            return;
        }
    }
    cout << "No se encontro el producto\n";
}

// Lista del inventario
void generarReporte() {
    cout << "\n--- Inventario ---\n";
    for (int i = 0; i < TotaldeProductos; i++) {
        cout << "Codigo: " << codigo[i]
             << " | Nombre: " << nombres[i]
             << " | Stock: " << stock[i]
             << " | Precio: $" << precios[i] << "\n";
    }
}

// Muestra el producto con un mayor precio
void productoMasCaro() {
    if (TotaldeProductos == 0) {
        cout << "Sin productos\n";
        return;
    }
    int idx = 0;
    for (int i = 1; i < TotaldeProductos; i++) {
        if (precios[i] > precios[idx]) idx = i;
    }
    cout << "El producto mas caro es: " << nombres[idx]
         << " con precio $" << precios[idx] << "\n";
}

// menu de opciones y bienvenida
int main() {
    cout << "--- Bienvenido al Sistema de Inventario de \"El Martillo\" ---\n";
    InventarioDeProductos();

    int opcion;
    do {
        cout << "\nMenu:\n";
        cout << "1. Consultar producto\n";
        cout << "2. Actualizar inventario\n";
        cout << "3. Generar reporte completo\n";
        cout << "4. Producto mas caro\n";
        cout << "5. Salir\n";
        cout << "Opcion: ";
        cout.flush(); 
        cin >> opcion;

        if (opcion == 1) {
            consultarProducto();
        } else if (opcion == 2) {
            actualizarInventario();
        } else if (opcion == 3) {
            generarReporte();
        } else if (opcion == 4) {
            productoMasCaro();
        }
    } while (opcion != 5);

    cout << "Saliste del programa...\n";
    return 0;
}