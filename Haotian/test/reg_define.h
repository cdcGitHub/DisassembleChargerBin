union REG_AX
{
    unsigned short int _World;
    struct  {
        unsigned char A:8;
        unsigned char X:8;
    }_byte;
}reg_AX;

union REG_BC
{
    unsigned short int _World;
    struct  {
        unsigned char B:8;
        unsigned char C:8;
    }_byte;
}reg_BC;

union REG_DE
{
    unsigned short int _World;
    struct  {
        unsigned char D:8;
        unsigned char E:8;
    }_byte;
}reg_DE;

union REG_HL
{
    unsigned short int _World;
    struct  {
        unsigned char H:8;
        unsigned char L:8;
    }_byte;
}reg_HL;

#define AX reg_AX._World
#define A  reg_AX._byte.A
#define X  reg_AX._byte.X

#define BC reg_BC._World
#define B  reg_BC._byte.B
#define C  reg_BC._byte.C

#define DE reg_DE._World
#define D  reg_DE._byte.D
#define E  reg_DE._byte.E

#define HL reg_HL._World
#define H  reg_HL._byte.H
#define L  reg_HL._byte.L