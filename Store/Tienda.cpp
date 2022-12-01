#include "Tienda.h"
#include <string>
#include <vector>
#include "Producto.h"
#include "Cliente.h"
#include <iostream>
#include <fstream>

/*
* CONSTRUCTORES
*/
Tienda::Tienda()
{
    identificadorT = "";
    nombre = "";
    direccion = "";
    cantidadProductosT = 0;
    cantidadClientesT = 0;
    productos = {};
    clientes = {};
    ingresoDiario = 0;

}

Tienda::Tienda(std::string _identificador, std::string _nombre, std::string _direccion, int _cantidadProductosT, int cantidadClientesT, std::vector<Producto> _productos, std::vector<Cliente> _clientes, double _ingresoDiario)
{
    identificadorT = _identificador;
    nombre = _nombre;
    direccion = _direccion;
    cantidadProductosT = _cantidadProductosT;
    cantidadClientesT = cantidadClientesT;
    productos = _productos;
    clientes = _clientes;
    ingresoDiario = _ingresoDiario;
}
// DESTRUCTOR
Tienda::~Tienda()
{
}
// GETTERS 
std::string Tienda::getIdentificadorT()
{
    return identificadorT;
}

std::string Tienda::getNombre()
{
    return nombre;
}

std::string Tienda::getDireccion()
{
    return direccion;
}

int Tienda::getCantidadProductosT()
{
    return cantidadProductosT;
}

int Tienda::getCantidadClientesT()
{
    return cantidadClientesT;
}

std::vector<Producto> Tienda::getProductos()
{
    return productos;
}

std::vector<Cliente> Tienda::getClientes()
{
    return clientes;
}

double Tienda::getIngresoDiario()
{
    return ingresoDiario;
}

// SETTERS
void Tienda::setIdentificadorT(std::string _identificador)
{
    identificadorT = _identificador;
}

void Tienda::setNombre(std::string _nombre)
{
    nombre = _nombre;
}

void Tienda::setDireccion(std::string _direccion)
{
    direccion = _direccion;
}

void Tienda::setCantidadProductosT(int _cantidadProductos)
{
    cantidadProductosT = _cantidadProductos;
}

void Tienda::setCantidadClientesT(int _cantidadClientesT)
{
    cantidadClientesT = _cantidadClientesT;
}

void Tienda::setProductos(std::vector<Producto> _productos)
{
    productos = _productos;
}

void Tienda::setClientes(std::vector<Cliente> _clientes)
{
    clientes = _clientes;
}
void Tienda::setIngresoDiario(double _ingreso) {
    ingresoDiario = _ingreso;
}
/*
* METODOS PERSONALIZADOS
    IMPRMIR TIENDA
    AGREGAR PRODUCTOS
    AGREGAR PRODUCTO
    AGREGAR CLIENTE
    LLENAR CARRITO
    IMPRIMIR TICKET COMPRA
    CERRAR OPERACIONES
*/
void Tienda::imprimirTienda()
{
    std::cout << "IMPRIMIR TIENDA" << std::endl;
    std::cout << "Identificador: " << getIdentificadorT() << std::endl;
    std::cout << "Nombre: " << getNombre() << std::endl;
    std::cout << "Direccion: " << getDireccion() << std::endl;
    std::cout << "Cantidad de Productos: " << getCantidadProductosT() << std::endl;
    std::cout << "Cantidad de Clientes: " << getCantidadClientesT() << std::endl;
    std::cout << "Productos Disponibles: " << std::endl;
    for (Producto producto : productos) {
        producto.imprimir();
    }
    std::cout << "********************************************" << std::endl;
    std::cout << "Clientes Registrados: " << std::endl;
    for (Cliente cliente : clientes) {
        cliente.imprimirCliente();
    }
    std::cout << "********************************************" << std::endl;
    std::cout << "Corte de caja (Cierre de dia): " << getIngresoDiario() << std::endl;
}

void Tienda::agregarProductos(std::string nombreDelArchivo)
{
    // Nombre del archivo
    std::string nombreArchivo = nombreDelArchivo;
    // ifstream para cargar el archivo
    std::ifstream archivo(nombreArchivo.c_str());
    // fila de archivo, o linea antes del enter
    std::string linea;
    // almacenador de las lineas
    std::vector<std::string> parametrosSeparados;
    // vector de toda la data en vector
    std::vector<std::string> dataOrdenada;
    // Obtener línea de archivo, y almacenar contenido en "linea"
    while (getline(archivo, linea)) {
        // leemos linea por linea y guardamos en la variable parametrosSeparados
        parametrosSeparados.push_back(linea);
    }
    // ahora con parametros separados, separamos los campos. Con esto, ya tenemos el nombre, categoria, precio, cantidad
    // el id lo generaremos apartir del nombre y categoria
    for (std::string lineaEvaluar : parametrosSeparados) {
        int apuntador = 0;
        for (int iteracion = 0; iteracion < lineaEvaluar.length(); iteracion++) {
            if (lineaEvaluar[iteracion] == ',') {
                dataOrdenada.push_back(lineaEvaluar.substr(apuntador, iteracion - apuntador));
                apuntador = iteracion + 1;
            }
        }
    }
    std::vector<Producto> coleccionDeProductos{};
    if (getProductos().size() > 0) {
        coleccionDeProductos = getProductos();
    }
    int totalProductos = getCantidadProductosT();
    // tercer y ultimo ciclo
    // sabiendo que nuestro txt son 4 campos (nombre, categoria, precio, cantidad)
    // podemos hacer una iteracion de 4 en 4, dado que ya sabemos que espacio pertenencen
    // ejemplo: [manzana, 1, 55, 100] donde dataOrdenada[0] es manzana, dataOrdenada[4] sera Pera
    for (int iterador = 0; iterador < dataOrdenada.size(); iterador=iterador+4) {
        // De-estructuracion del archivo
        // nombre - categoria - precio - cantidad
        std::string nombre = dataOrdenada[iterador];
        std::string categoria = dataOrdenada[iterador+1];
        std::string precio = dataOrdenada[iterador+2];
        std::string cantidad = dataOrdenada[iterador+3];
        // checamos que no se repita el dato
        bool repetido = false;
        if (getProductos().size() > 0) {
            std::vector<Producto> productosActuales = getProductos();
            for (int y_iteracion = 0; y_iteracion < productosActuales.size(); y_iteracion++) {
                Producto item = productosActuales[y_iteracion];
                // como estamos evaluando los ya existentes, la coleccion ya lo tiene incluido, apuntamos a su locacion y lo editamos
                if (item.getClave() == categoria+nombre) {
                    std::cout << y_iteracion << nombre << std::endl;
                    item.setCantidad(std::stoi(cantidad));
                    item.setPrecioP(std::stof(precio));
                    coleccionDeProductos[y_iteracion].setCantidad(std::stoi(cantidad));
                    coleccionDeProductos[y_iteracion].setPrecioP(std::stof(precio));
                    repetido = true;
                    totalProductos += std::stoi(cantidad);
                    break;
                }
            }
        }
        if (!repetido) {
            Producto productoBasadoDatos(categoria + nombre, nombre, std::stoi(categoria), std::stof(precio), std::stoi(cantidad));
            coleccionDeProductos.push_back(productoBasadoDatos);
            totalProductos = std::stoi(cantidad);
        }
    }
    setCantidadProductosT(totalProductos);
    setProductos(coleccionDeProductos);
}

void Tienda::agregarProducto()
{
    std::string clave;
    std::string nombreP;
    int categoriaP;
    float precioP;
    int cantidad;
    std::string generarClave = "";
    bool errorEnCat = true;
    std::cout << "Ingrese el nombre del producto" << std::endl;
    std::cin >> nombreP;
    while (errorEnCat) {
        std::cout << "Ingrese la categoria de las 5 disponibles" << std::endl;
        std::cout << "1- Frutas y Verduras" << std::endl;
        std::cout << "2- Electrodomesticos" << std::endl;
        std::cout << "3- Abarrotes" << std::endl;
        std::cout << "4- Higiene Personal" << std::endl;
        std::cout << "5- Jardineria" << std::endl;
        std::cin >> categoriaP;
        if (categoriaP > 5 || categoriaP < 0) {
            errorEnCat = true;
            system("CLS");
        }
        else {
            errorEnCat = false;
        }
    };
    std::cout << "Desea que generemos el identificador apartir del nombre y categoria? y/n" << std::endl;
    std::cin >> generarClave;
    if (generarClave == "y" || generarClave == "yes" || generarClave == "Y" || generarClave == "YES") {
        clave = std::to_string(categoriaP) + nombreP;
    }
    else {
        std::cout << "Ingrese su clave" << std::endl;
        std::cin >> clave;
    }
    std::cout << "Ingrese el precio" << std::endl;
    std::cin >> precioP;
    std::cout << "Ingrese cantidad" << std::endl;
    std::cin >> cantidad;
    Producto nuevoProducto(clave, nombreP, categoriaP, precioP, cantidad);
    if (getProductos().size() > 0) {
        std::vector<Producto> coleccionDeProductos{};
        coleccionDeProductos = getProductos();
        bool repetido = false;
        for (int iteracion = 0; iteracion < coleccionDeProductos.size(); iteracion++) {
            if (coleccionDeProductos[iteracion].getClave() == clave) {
                coleccionDeProductos[iteracion].setCantidad(cantidad);
                coleccionDeProductos[iteracion].setPrecioP(precioP);
                repetido = true;
                break;
            }
        }
        if (!repetido) {
            coleccionDeProductos.push_back(nuevoProducto);
        }
        setProductos(coleccionDeProductos);
    }
    else {
        setProductos({ nuevoProducto });
    }
    setCantidadProductosT(cantidad + getCantidadProductosT());
    return ;
}

void Tienda::agregarCliente()
{
    std::string identificador;
    std::string nombreC;
    std::string correoElectronico;
    std::string telefono;
    std::vector<Producto> productos;
    double totalCompra = 0;
    std::cout << "Identificador" << std::endl;
    std::cin >> identificador;
    std::cout << "Nombre" << std::endl;
    std::cin >> nombreC;
    std::cout << "Correo Electronico" << std::endl;
    std::cin >> correoElectronico;
    std::cout << "Telefono" << std::endl;
    std::cin >> telefono;
    Cliente clienteNuevo(identificador, nombre, correoElectronico, telefono, productos, totalCompra);
    std::vector<Cliente> coleccionDeClientesActualizada = getClientes();
    coleccionDeClientesActualizada.push_back(clienteNuevo);
    setClientes(coleccionDeClientesActualizada);
    setCantidadClientesT(getCantidadClientesT() + 1);
}

void Tienda::llenarCarrito()
{
    if (getClientes().size() == 0) {
        std::cout << "Ningun cliente registrado, regresando al menu anterior." << std::endl;
        return;
    }
    std::string identificador = "";
    std::cout << "Ingrese su identificador" << std::endl;
    std::cin >> identificador;
    int existe = 0;
    int posicion = 0;
    for (int iteracion = 0; iteracion < getClientes().size(); iteracion++) {
        Cliente item = getClientes()[iteracion];
        if (item.getIdentificador() == identificador) {
            existe = 1;
            posicion = iteracion;
            break;
        }
    }
    if (existe == 0) {
        std::cout << "Ningun cliente registrado, regresando al menu anterior." << std::endl;
        return;
    }
    int menuOpcion = 0;
    int salir = 0;
    std::vector<std::string> idsAComprar{};
    std::vector<int> cantidadesAComprar{};
    std::vector<Producto> listaDeProductos = getProductos();
    while (salir == 0) {
        std::cout << "*************************" << std::endl;
        std::cout << "Seleccione La Categoria De Productos" << std::endl;
        std::cout << "*************************" << std::endl;
        std::cout << "1- Frutas y Verduras" << std::endl;
        std::cout << "2- Electrodomesticos" << std::endl;
        std::cout << "3- Abarrotes" << std::endl;
        std::cout << "4- Higiene Personal" << std::endl;
        std::cout << "5- Jardineria" << std::endl;
        std::cout << "6- Salir" << std::endl;
        std::cin >> menuOpcion;
        if (menuOpcion >= 0 && menuOpcion <= 5) {
            std::string temporalId = "";
            int temporalCantidad = 0;
            std::cout << "Identificador - Nombre - Cantidad - Precio" << std::endl;
            for (Producto producto : listaDeProductos) {
                if (producto.getCategoriaP() == menuOpcion) {
                    std::cout << producto.getClave() << "..." << producto.getNombreP() << "..." << producto.getCantidad() << "..." << producto.getPrecioP() << std::endl;
                }
            }
            std::cout << "Escriba el id del producto" << std::endl;
            std::cin >> temporalId;
            std::cout << "Escriba la cantidad del producto" << std::endl;
            std::cin >> temporalCantidad;
            idsAComprar.push_back(temporalId);
            cantidadesAComprar.push_back(temporalCantidad);
        }
        else if (menuOpcion == 6) {
            salir = 1;
        }
        else {
            std::cout << "Opcion No Valida." << std::endl;
        }
    }
    std::vector<Producto> shoppingList;
    for (int iteracion = 0; iteracion < cantidadesAComprar.size(); iteracion++) {
        for (Producto producto : listaDeProductos) {
            if (producto.getClave() == idsAComprar[iteracion]) {
                Producto objetoComprar(producto);
                objetoComprar.setCantidad(cantidadesAComprar[iteracion]);
                shoppingList.push_back(objetoComprar);
                break;
            }
        }
    }
    std::vector<Cliente> clienteActualizados;
    for(Cliente cliente: getClientes()){
        if (cliente.getIdentificador() == identificador)
        {
            std::vector<Producto> productosDelCliente = cliente.getProductos();
            productosDelCliente.insert(productosDelCliente.end(), shoppingList.begin(), shoppingList.end());
            cliente.setProductos(productosDelCliente);
        }
        clienteActualizados.push_back(cliente);
    }
    setClientes(clienteActualizados);
}

void Tienda::imprimirTicketCompra()
{
    if (getClientes().size() == 0) {
        std::cout << "Ningun cliente registrado, regresando al menu anterior." << std::endl;
        return;
    }
    std::string identificador = "";
    std::cout << "Ingrese su identificador" << std::endl;
    std::cin >> identificador;
    int existe = 0;
    int posicion = 0;
    for (int iteracion = 0; iteracion < getClientes().size(); iteracion++) {
        Cliente item = getClientes()[iteracion];
        if (item.getIdentificador() == identificador) {
            existe = 1;
            posicion = iteracion;
            break;
        }
    }
    if (existe == 0) {
        std::cout << "Ningun cliente registrado, regresando al menu anterior." << std::endl;
        return;
    }
    std::vector<Producto> productosTienda;
    std::vector<Cliente> clienteData;
    // Imprimimos recibo de pago, actualizamos el stock de la tienda, limpiamos usuario-carrito
    for (Cliente clientePagando : getClientes()) {
        double grandTotal = 0;
        if (clientePagando.getIdentificador() == identificador) {
            std::cout << "Articulo" << "Cantidad" << "Precio Unitario" << std::endl;
            for (Producto producto : clientePagando.getProductos()) {
                grandTotal += producto.getCantidad() * producto.getPrecioP();
                std::cout << producto.getNombreP() << "..." << producto.getCantidad() << "..." << producto.getPrecioP() << "..." << producto.getCantidad() * producto.getPrecioP() << std::endl;
                for (Producto stock : getProductos()) {
                    if (stock.getClave() == producto.getClave()) {
                        stock.setCantidad(stock.getCantidad() - producto.getCantidad());
                    }
                    productosTienda.push_back(stock);
                }
            }
            std::cout << "TOTAL.........................." << grandTotal << std::endl;
            setIngresoDiario(getIngresoDiario() + grandTotal);
            std::vector<Producto> resetProducts;
            clientePagando.setProductos(resetProducts);
            clientePagando.setTotalCompra(0);
        }
        clienteData.push_back(clientePagando);
    }
    int contador = 0;
    for (Producto tiendaConteos : productosTienda) {
        contador += tiendaConteos.getCantidad();
    }
    setCantidadProductosT(contador);
    setProductos(productosTienda);
    setClientes(clienteData);
}

void Tienda::cerrarOperaciones()
{
    std::cout << "Cierre de Caja" << std::endl;
    std::cout << "-----------------------" << std::endl;
    std::cout << "INVENTARIO FINALIZADO EL DIA:" << std::endl;
    imprimirTienda();
    std::cout << "-----------------------" << std::endl;
    std::cout << "TOTAL GANADO EN EL DIA.........................." << getIngresoDiario() << std::endl;
}
