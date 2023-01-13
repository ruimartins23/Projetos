
// declaration of structures
// estrutura estudante
typedef struct Student
{
    int id;
    char *name;
    char *nationality;
} Student;

// lista de estudantes
typedef struct SListSt
{
    Student student;
    struct SListSt *next;
} StudentList;

// estrutura UC
typedef struct UC
{
    int id_uc;
    int year;
    int semester;
    int etcs;
    char *name;
} UC;

// lista de UCs
typedef struct SListUC
{
    UC uc;
    struct SListUC *next;
} UCList;

// Enrollment
typedef struct Enrollment
{
    int student_id;
    int uc_id;
} Enrollment;

// lista de enrollment
typedef struct SListEnr
{
    Enrollment enrollment;
    struct SListEnr *next;
} EnrollmentList;
