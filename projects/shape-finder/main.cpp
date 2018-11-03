#include <iostream>
#include <fstream>
#include <memory>

int main()
{
    std::ifstream in( "shapes.ppm", std::ios::binary );

    in.seekg( 0, std::ios::end );
    auto size = in.tellg();
    in.seekg( 0 );

    std::unique_ptr< char[] > buffer( new char[ size ] );

    in.read( buffer.get(), size );

    for(int i = 0; i < size; i++)
    {
        
        std::cout << buffer[i] << std::endl;
    }

    in.close();

    return 0;
}