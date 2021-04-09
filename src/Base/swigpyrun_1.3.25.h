/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.25
 * 
 * This file is not intended to be easily readable and contains a number of 
 * coding conventions designed to improve portability and efficiency. Do not make
 * changes to this file unless you know what you are doing--modify the SWIG 
 * interface file instead. 
 * ----------------------------------------------------------------------------- */

/***********************************************************************
 *
 *  This section contains generic SWIG labels for method/variable
 *  declarations/attributes, and other compiler dependent labels.
 *
 ************************************************************************/

/* template workaround for compilers that cannot correctly implement the C++ standard */
#ifndef SWIGTEMPLATEDISAMBIGUATOR
#  if defined(__SUNPRO_CC) && (__SUNPRO_CC <= 0x560)
#    define SWIGTEMPLATEDISAMBIGUATOR template
#  else
#    define SWIGTEMPLATEDISAMBIGUATOR 
#  endif
#endif

/* inline attribute */
#ifndef SWIGINLINE
# if defined(__cplusplus) || (defined(__GNUC__) && !defined(__STRICT_ANSI__))
#   define SWIGINLINE inline
# else
#   define SWIGINLINE
# endif
#endif

/* attribute recognised by some compilers to avoid 'unused' warnings */
#ifndef SWIGUNUSED
# if defined(__GNUC__) || defined(__ICC)
#   define SWIGUNUSED __attribute__ ((unused)) 
# else
#   define SWIGUNUSED 
# endif
#endif

/* internal SWIG method */
#ifndef SWIGINTERN
# define SWIGINTERN static SWIGUNUSED
#endif

/* internal inline SWIG method */
#ifndef SWIGINTERNINLINE
# define SWIGINTERNINLINE SWIGINTERN SWIGINLINE
#endif

/* exporting methods for Windows DLLs */
#ifndef SWIGEXPORT
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   if defined(STATIC_LINKED)
#     define SWIGEXPORT
#   else
#     define SWIGEXPORT __declspec(dllexport)
#   endif
# else
#   define SWIGEXPORT
# endif
#endif

/* calling conventions for Windows */
#ifndef SWIGSTDCALL
# if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
#   define SWIGSTDCALL __stdcall
# else
#   define SWIGSTDCALL
# endif 
#endif


/***********************************************************************
 * swigrun.swg
 *
 *     This file contains generic CAPI SWIG runtime support for pointer
 *     type checking.
 *
 ************************************************************************/

/* This should only be incremented when either the layout of swig_type_info changes,
   or for whatever reason, the runtime changes incompatibly */
#define SWIG_RUNTIME_VERSION "2"

/* define SWIG_TYPE_TABLE_NAME as "SWIG_TYPE_TABLE" */
#ifdef SWIG_TYPE_TABLE
# define SWIG_QUOTE_STRING(x) #x
# define SWIG_EXPAND_AND_QUOTE_STRING(x) SWIG_QUOTE_STRING(x)
# define SWIG_TYPE_TABLE_NAME SWIG_EXPAND_AND_QUOTE_STRING(SWIG_TYPE_TABLE)
#else
# define SWIG_TYPE_TABLE_NAME
#endif

/*
  You can use the SWIGRUNTIME and SWIGRUNTIMEINLINE macros for
  creating a static or dynamic library from the swig runtime code.
  In 99.9% of the cases, swig just needs to declare them as 'static'.
  
  But only do this if is strictly necessary, ie, if you have problems
  with your compiler or so.
*/

#ifndef SWIGRUNTIME
# define SWIGRUNTIME SWIGINTERN
#endif

#ifndef SWIGRUNTIMEINLINE
# define SWIGRUNTIMEINLINE SWIGRUNTIME SWIGINLINE
#endif

#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void *(*swig_converter_func)(void *);
typedef struct swig_type_info *(*swig_dycast_func)(void **);

/* Structure to store inforomation on one type */
typedef struct swig_type_info {
  const char             *name;			/* mangled name of this type */
  const char             *str;			/* human readable name of this type */
  swig_dycast_func        dcast;		/* dynamic cast function down a hierarchy */
  struct swig_cast_info  *cast;			/* linked list of types that can cast into this type */
  void                   *clientdata;		/* language specific type data */
} swig_type_info;

/* Structure to store a type and conversion function used for casting */
typedef struct swig_cast_info {
  swig_type_info         *type;			/* pointer to type that is equivalent to this type */
  swig_converter_func     converter;		/* function to cast the void pointers */
  struct swig_cast_info  *next;			/* pointer to next cast in linked list */
  struct swig_cast_info  *prev;			/* pointer to the previous cast */
} swig_cast_info;

/* Structure used to store module information
 * Each module generates one structure like this, and the runtime collects
 * all of these structures and stores them in a circularly linked list.*/
typedef struct swig_module_info {
  swig_type_info         **types;		/* Array of pointers to swig_type_info structures that are in this module */
  size_t                 size;		        /* Number of types in this module */
  struct swig_module_info *next;		/* Pointer to next element in circularly linked list */
  swig_type_info         **type_initial;	/* Array of initially generated type structures */
  swig_cast_info         **cast_initial;	/* Array of initially generated casting structures */
  void                    *clientdata;		/* Language specific module data */
} swig_module_info;


/* 
  Compare two type names skipping the space characters, therefore
  "char*" == "char *" and "Class<int>" == "Class<int >", etc.

  Return 0 when the two name types are equivalent, as in
  strncmp, but skipping ' '.
*/
SWIGRUNTIME int
SWIG_TypeNameComp(const char *f1, const char *l1,
		  const char *f2, const char *l2) {
  for (;(f1 != l1) && (f2 != l2); ++f1, ++f2) {
    while ((*f1 == ' ') && (f1 != l1)) ++f1;
    while ((*f2 == ' ') && (f2 != l2)) ++f2;
    if (*f1 != *f2) return (int)(*f1 - *f2);
  }
  return (l1 - f1) - (l2 - f2);
}

/*
  Check type equivalence in a name list like <name1>|<name2>|...
  Return 0 if not equal, 1 if equal
*/
SWIGRUNTIME int
SWIG_TypeEquiv(const char *nb, const char *tb) {
  int equiv = 0;
  const char* te = tb + strlen(tb);
  const char* ne = nb;
  while (!equiv && *ne) {
    for (nb = ne; *ne; ++ne) {
      if (*ne == '|') break;
    }
    equiv = (SWIG_TypeNameComp(nb, ne, tb, te) == 0) ? 1 : 0;
    if (*ne) ++ne;
  }
  return equiv;
}

/*
  Check type equivalence in a name list like <name1>|<name2>|...
  Return 0 if equal, -1 if nb < tb, 1 if nb > tb
*/
SWIGRUNTIME int
SWIG_TypeCompare(const char *nb, const char *tb) {
  int equiv = 0;
  const char* te = tb + strlen(tb);
  const char* ne = nb;
  while (!equiv && *ne) {
    for (nb = ne; *ne; ++ne) {
      if (*ne == '|') break;
    }
    equiv = (SWIG_TypeNameComp(nb, ne, tb, te) == 0) ? 1 : 0;
    if (*ne) ++ne;
  }
  return equiv;
}


/* think of this as a c++ template<> or a scheme macro */
#define SWIG_TypeCheck_Template(comparison, ty)         \
  if (ty) {                                             \
    swig_cast_info *iter = ty->cast;                    \
    while (iter) {                                      \
      if (comparison) {                                 \
        if (iter == ty->cast) return iter;              \
        /* Move iter to the top of the linked list */   \
        iter->prev->next = iter->next;                  \
        if (iter->next)                                 \
          iter->next->prev = iter->prev;                \
        iter->next = ty->cast;                          \
        iter->prev = 0;                                 \
        if (ty->cast) ty->cast->prev = iter;            \
        ty->cast = iter;                                \
        return iter;                                    \
      }                                                 \
      iter = iter->next;                                \
    }                                                   \
  }                                                     \
  return 0

/*
  Check the typename
*/
SWIGRUNTIME swig_cast_info *
SWIG_TypeCheck(const char *c, swig_type_info *ty) {
  SWIG_TypeCheck_Template(strcmp(iter->type->name, c) == 0, ty);
}

/* Same as previous function, except strcmp is replaced with a pointer comparison */
SWIGRUNTIME swig_cast_info *
SWIG_TypeCheckStruct(swig_type_info *from, swig_type_info *into) {
  SWIG_TypeCheck_Template(iter->type == from, into);
}

/*
  Cast a pointer up an inheritance hierarchy
*/
SWIGRUNTIMEINLINE void *
SWIG_TypeCast(swig_cast_info *ty, void *ptr) {
  return ((!ty) || (!ty->converter)) ? ptr : (*ty->converter)(ptr);
}

/* 
   Dynamic pointer casting. Down an inheritance hierarchy
*/
SWIGRUNTIME swig_type_info *
SWIG_TypeDynamicCast(swig_type_info *ty, void **ptr) {
  swig_type_info *lastty = ty;
  if (!ty || !ty->dcast) return ty;
  while (ty && (ty->dcast)) {
    ty = (*ty->dcast)(ptr);
    if (ty) lastty = ty;
  }
  return lastty;
}

/*
  Return the name associated with this type
*/
SWIGRUNTIMEINLINE const char *
SWIG_TypeName(const swig_type_info *ty) {
  return ty->name;
}

/*
  Return the pretty name associated with this type,
  that is an unmangled type name in a form presentable to the user.
*/
SWIGRUNTIME const char *
SWIG_TypePrettyName(const swig_type_info *type) {
  /* The "str" field contains the equivalent pretty names of the
     type, separated by vertical-bar characters.  We choose
     to print the last name, as it is often (?) the most
     specific. */
  if (type->str != NULL) {
    const char *last_name = type->str;
    const char *s;
    for (s = type->str; *s; s++)
      if (*s == '|') last_name = s+1;
    return last_name;
  }
  else
    return type->name;
}

/* 
   Set the clientdata field for a type
*/
SWIGRUNTIME void
SWIG_TypeClientData(swig_type_info *ti, void *clientdata) {
  if (!ti->clientdata) {
    swig_cast_info *cast = ti->cast;
    /* if (ti->clientdata == clientdata) return; */
    ti->clientdata = clientdata;
    
    while (cast) {
      if (!cast->converter)
	SWIG_TypeClientData(cast->type, clientdata);
      cast = cast->next;
    }
  }
}

/*
  Search for a swig_type_info structure only by mangled name
  Search is a O(log #types)
  
  We start searching at module start, and finish searching when start == end.  
  Note: if start == end at the beginning of the function, we go all the way around
  the circular list.
*/
SWIGRUNTIME swig_type_info *
SWIG_MangledTypeQueryModule(swig_module_info *start, 
                            swig_module_info *end, 
		            const char *name) {
  swig_module_info *iter = start;
  do {
    if (iter->size) {
      register size_t l = 0;
      register size_t r = iter->size - 1;
      do {
	/* since l+r >= 0, we can (>> 1) instead (/ 2) */
	register size_t i = (l + r) >> 1; 
	const char *iname = iter->types[i]->name;
	if (iname) {
	  register int compare = strcmp(name, iname);
	  if (compare == 0) {	    
	    return iter->types[i];
	  } else if (compare < 0) {
	    if (i) {
	      r = i - 1;
	    } else {
	      break;
	    }
	  } else if (compare > 0) {
	    l = i + 1;
	  }
	} else {
	  break; /* should never happen */
	}
      } while (l <= r);
    }
    iter = iter->next;
  } while (iter != end);
  return 0;
}

/*
  Search for a swig_type_info structure for either a mangled name or a human readable name.
  It first searches the mangled names of the types, which is a O(log #types)
  If a type is not found it then searches the human readable names, which is O(#types).
  
  We start searching at module start, and finish searching when start == end.  
  Note: if start == end at the beginning of the function, we go all the way around
  the circular list.
*/
SWIGRUNTIME swig_type_info *
SWIG_TypeQueryModule(swig_module_info *start, 
                     swig_module_info *end, 
		     const char *name) {
  /* STEP 1: Search the name field using binary search */
  swig_type_info *ret = SWIG_MangledTypeQueryModule(start, end, name);
  if (ret) {
    return ret;
  } else {
    /* STEP 2: If the type hasn't been found, do a complete search
       of the str field (the human readable name) */
    swig_module_info *iter = start;
    do {
      register size_t i = 0;
      for (; i < iter->size; ++i) {
	if (iter->types[i]->str && (SWIG_TypeEquiv(iter->types[i]->str, name)))
	  return iter->types[i];
      }
      iter = iter->next;
    } while (iter != end);
  }
  
  /* neither found a match */
  return 0;
}


/* 
   Pack binary data into a string
*/
SWIGRUNTIME char *
SWIG_PackData(char *c, void *ptr, size_t sz) {
  static const char hex[17] = "0123456789abcdef";
  register const unsigned char *u = (unsigned char *) ptr;
  register const unsigned char *eu =  u + sz;
  for (; u != eu; ++u) {
    register unsigned char uu = *u;
    *(c++) = hex[(uu & 0xf0) >> 4];
    *(c++) = hex[uu & 0xf];
  }
  return c;
}

/* 
   Unpack binary data from a string
*/
SWIGRUNTIME const char *
SWIG_UnpackData(const char *c, void *ptr, size_t sz) {
  register unsigned char *u = (unsigned char *) ptr;
  register const unsigned char *eu = u + sz;
  for (; u != eu; ++u) {
    register char d = *(c++);
    register unsigned char uu = 0;
    if ((d >= '0') && (d <= '9'))
      uu = ((d - '0') << 4);
    else if ((d >= 'a') && (d <= 'f'))
      uu = ((d - ('a'-10)) << 4);
    else 
      return (char *) 0;
    d = *(c++);
    if ((d >= '0') && (d <= '9'))
      uu |= (d - '0');
    else if ((d >= 'a') && (d <= 'f'))
      uu |= (d - ('a'-10));
    else 
      return (char *) 0;
    *u = uu;
  }
  return c;
}

/* 
   Pack 'void *' into a string buffer.
*/
SWIGRUNTIME char *
SWIG_PackVoidPtr(char *buff, void *ptr, const char *name, size_t bsz) {
  char *r = buff;
  if ((2*sizeof(void *) + 2) > bsz) return 0;
  *(r++) = '_';
  r = SWIG_PackData(r,&ptr,sizeof(void *));
  if (strlen(name) + 1 > (bsz - (r - buff))) return 0;
  strcpy(r,name);
  return buff;
}

SWIGRUNTIME const char *
SWIG_UnpackVoidPtr(const char *c, void **ptr, const char *name) {
  if (*c != '_') {
    if (strcmp(c,"NULL") == 0) {
      *ptr = (void *) 0;
      return name;
    } else {
      return 0;
    }
  }
  return SWIG_UnpackData(++c,ptr,sizeof(void *));
}

SWIGRUNTIME char *
SWIG_PackDataName(char *buff, void *ptr, size_t sz, const char *name, size_t bsz) {
  char *r = buff;
  size_t lname = (name ? strlen(name) : 0);
  if ((2*sz + 2 + lname) > bsz) return 0;
  *(r++) = '_';
  r = SWIG_PackData(r,ptr,sz);
  if (lname) {
    strncpy(r,name,lname+1);
  } else {
    *r = 0;
  }
  return buff;
}

SWIGRUNTIME const char *
SWIG_UnpackDataName(const char *c, void *ptr, size_t sz, const char *name) {
  if (*c != '_') {
    if (strcmp(c,"NULL") == 0) {
      memset(ptr,0,sz);
      return name;
    } else {
      return 0;
    }
  }
  return SWIG_UnpackData(++c,ptr,sz);
}

#ifdef __cplusplus
}
#endif

/***********************************************************************
 * pyrun.swg
 *
 *     This file contains the runtime support for Python modules
 *     and includes code for managing global variables and pointer
 *     type checking.
 *
 * Author : David Beazley (beazley@cs.uchicago.edu)
 ************************************************************************/

/* Common SWIG API */
#define SWIG_ConvertPtr(obj, pp, type, flags)    SWIG_Python_ConvertPtr(obj, pp, type, flags)
#define SWIG_NewPointerObj(p, type, flags)       SWIG_Python_NewPointerObj(p, type, flags)
#define SWIG_MustGetPtr(p, type, argnum, flags)  SWIG_Python_MustGetPtr(p, type, argnum, flags)
 

/* Python-specific SWIG API */
#define SWIG_ConvertPacked(obj, ptr, sz, ty, flags)   SWIG_Python_ConvertPacked(obj, ptr, sz, ty, flags)
#define SWIG_NewPackedObj(ptr, sz, type)              SWIG_Python_NewPackedObj(ptr, sz, type)

/* Runtime API */
#define SWIG_GetModule(clientdata) SWIG_Python_GetModule()
#define SWIG_SetModule(clientdata, pointer) SWIG_Python_SetModule(pointer)

/* -----------------------------------------------------------------------------
 * Pointer declarations
 * ----------------------------------------------------------------------------- */
/*
  Use SWIG_NO_COBJECT_TYPES to force the use of strings to represent
  C/C++ pointers in the python side. Very useful for debugging, but
  not always safe.
*/
#if !defined(SWIG_NO_COBJECT_TYPES) && !defined(SWIG_COBJECT_TYPES)
#  define SWIG_COBJECT_TYPES
#endif

/* Flags for pointer conversion */
#define SWIG_POINTER_EXCEPTION     0x1
#define SWIG_POINTER_DISOWN        0x2


/* Add PyOS_snprintf for old Pythons */
#if PY_VERSION_HEX < 0x02020000
#define PyOS_snprintf snprintf
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* -----------------------------------------------------------------------------
 * Create a new pointer string 
 * ----------------------------------------------------------------------------- */
#ifndef SWIG_BUFFER_SIZE
#define SWIG_BUFFER_SIZE 1024
#endif

#if defined(SWIG_COBJECT_TYPES)
#if !defined(SWIG_COBJECT_PYTHON)
/* -----------------------------------------------------------------------------
 * Implements a simple Swig Object type, and use it instead of PyCObject
 * ----------------------------------------------------------------------------- */

typedef struct {
  PyObject_HEAD
  void *ptr;
  const char *desc;
} PySwigObject;

/* Declarations for objects of type PySwigObject */

SWIGRUNTIME int
PySwigObject_print(PySwigObject *v, FILE *fp, int flags)
{
  char result[SWIG_BUFFER_SIZE];
  flags = flags;
  if (SWIG_PackVoidPtr(result, v->ptr, v->desc, sizeof(result))) {
    fputs("<Swig Object at ", fp); fputs(result, fp); fputs(">", fp);
    return 0; 
  } else {
    return 1; 
  }
}
  
SWIGRUNTIME PyObject *
PySwigObject_repr(PySwigObject *v)
{
  char result[SWIG_BUFFER_SIZE];
  return SWIG_PackVoidPtr(result, v->ptr, v->desc, sizeof(result)) ?
    PyString_FromFormat("<Swig Object at %s>", result) : 0;
}

SWIGRUNTIME PyObject *
PySwigObject_str(PySwigObject *v)
{
  char result[SWIG_BUFFER_SIZE];
  return SWIG_PackVoidPtr(result, v->ptr, v->desc, sizeof(result)) ?
    PyString_FromString(result) : 0;
}

SWIGRUNTIME PyObject *
PySwigObject_long(PySwigObject *v)
{
  return PyLong_FromVoidPtr(v->ptr);
}

SWIGRUNTIME PyObject *
PySwigObject_format(const char* fmt, PySwigObject *v)
{
  PyObject *res = NULL;
  PyObject *args = PyTuple_New(1);
  if (args && (PyTuple_SetItem(args, 0, PySwigObject_long(v)) == 0)) {
    PyObject *ofmt = PyString_FromString(fmt);
    if (ofmt) {
      res = PyString_Format(ofmt,args);
      Py_DECREF(ofmt);
    }
    Py_DECREF(args);
  }  
  return res;
}

SWIGRUNTIME PyObject *
PySwigObject_oct(PySwigObject *v)
{
  return PySwigObject_format("%o",v);
}

SWIGRUNTIME PyObject *
PySwigObject_hex(PySwigObject *v)
{
  return PySwigObject_format("%x",v);
}

SWIGRUNTIME int
PySwigObject_compare(PySwigObject *v, PySwigObject *w)
{
  int c = strcmp(v->desc, w->desc);
  if (c) {
    return (c > 0) ? 1 : -1;
  } else {
    void *i = v->ptr;
    void *j = w->ptr;
    return (i < j) ? -1 : ((i > j) ? 1 : 0);
  }
}

SWIGRUNTIME void
PySwigObject_dealloc(PySwigObject *self)
{
  PyObject_DEL(self);
}

SWIGRUNTIME PyTypeObject*
PySwigObject_type(void) {
  static char pyswigobject_type__doc__[] = 
    "Swig object carries a C/C++ instance pointer";
  
  static PyNumberMethods PySwigObject_as_number = {
    (binaryfunc)0, /*nb_add*/
    (binaryfunc)0, /*nb_subtract*/
    (binaryfunc)0, /*nb_multiply*/
    (binaryfunc)0, /*nb_divide*/
    (binaryfunc)0, /*nb_remainder*/
    (binaryfunc)0, /*nb_divmod*/
    (ternaryfunc)0,/*nb_power*/
    (unaryfunc)0,  /*nb_negative*/
    (unaryfunc)0,  /*nb_positive*/
    (unaryfunc)0,  /*nb_absolute*/
    (inquiry)0,    /*nb_nonzero*/
    0,		   /*nb_invert*/
    0,		   /*nb_lshift*/
    0,		   /*nb_rshift*/
    0,		   /*nb_and*/
    0,		   /*nb_xor*/
    0,		   /*nb_or*/
    (coercion)0,   /*nb_coerce*/
    (unaryfunc)PySwigObject_long, /*nb_int*/
    (unaryfunc)PySwigObject_long, /*nb_long*/
    (unaryfunc)0,                 /*nb_float*/
    (unaryfunc)PySwigObject_oct,  /*nb_oct*/
    (unaryfunc)PySwigObject_hex,  /*nb_hex*/
#if PY_VERSION_HEX >= 0x02000000
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 /* nb_inplace_add -> nb_inplace_true_divide */ 
#endif
  };

  static PyTypeObject pyswigobject_type
#if !defined(__cplusplus)
  ;  
  static int type_init = 0;
  if (!type_init) {
    PyTypeObject tmp
#endif
    = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,					/*ob_size*/
    (char *)"PySwigObject",		/*tp_name*/
    sizeof(PySwigObject),		/*tp_basicsize*/
    0,					/*tp_itemsize*/
    /* methods */
    (destructor)PySwigObject_dealloc,	/*tp_dealloc*/
#if PY_VERSION_HEX < 0x03080000
    (printfunc)PySwigObject_print,	/*tp_print*/
#else
    0,          /*tp_vectorcall_offset*/
#endif
    (getattrfunc)0,			/*tp_getattr*/
    (setattrfunc)0,			/*tp_setattr*/
    (cmpfunc)PySwigObject_compare,	/*tp_compare*/
    (reprfunc)PySwigObject_repr,	/*tp_repr*/
    &PySwigObject_as_number,	        /*tp_as_number*/
    0,					/*tp_as_sequence*/
    0,					/*tp_as_mapping*/
    (hashfunc)0,			/*tp_hash*/
    (ternaryfunc)0,			/*tp_call*/
    (reprfunc)PySwigObject_str,		/*tp_str*/
    /* Space for future expansion */
    0,0,0,0,
    pyswigobject_type__doc__, 	        /* Documentation string */
#if PY_VERSION_HEX >= 0x02000000
    0,                                  /* tp_traverse */
    0,                                  /* tp_clear */
#endif
#if PY_VERSION_HEX >= 0x02010000
    0,                                  /* tp_richcompare */
    0,                                  /* tp_weaklistoffset */
#endif
#if PY_VERSION_HEX >= 0x02020000
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, /* tp_iter -> tp_weaklist */
#endif
#if PY_VERSION_HEX >= 0x02030000
    0,                                  /* tp_del */
#endif
#if PY_VERSION_HEX >= 0x02060000
    0,                                  /* tp_version_tag */
#endif
#ifdef COUNT_ALLOCS
    0,0,0,0                             /* tp_alloc -> tp_next */
#endif
    };
#if !defined(__cplusplus)
    pyswigobject_type = tmp;
    type_init = 1;
  }
#endif
  return &pyswigobject_type;
}

SWIGRUNTIME PyObject *
PySwigObject_FromVoidPtrAndDesc(void *ptr, const char *desc)
{
  PySwigObject *self = PyObject_NEW(PySwigObject, PySwigObject_type());
  if (self) {
    self->ptr = ptr;
    self->desc = desc;
  }
  return (PyObject *)self;
}

SWIGRUNTIMEINLINE void *
PySwigObject_AsVoidPtr(PyObject *self)
{
  return ((PySwigObject *)self)->ptr;
}

SWIGRUNTIMEINLINE const char *
PySwigObject_GetDesc(PyObject *self)
{
  return ((PySwigObject *)self)->desc;
}

SWIGRUNTIMEINLINE int
PySwigObject_Check(PyObject *op) {
  return ((op)->ob_type == PySwigObject_type()) 
    || (strcmp((op)->ob_type->tp_name,"PySwigObject") == 0);
}

/* -----------------------------------------------------------------------------
 * Implements a simple Swig Packed type, and use it instead of string
 * ----------------------------------------------------------------------------- */

typedef struct {
  PyObject_HEAD
  void *pack;
  const char *desc;
  size_t size;
} PySwigPacked;

SWIGRUNTIME int
PySwigPacked_print(PySwigPacked *v, FILE *fp, int flags)
{
  char result[SWIG_BUFFER_SIZE];
  flags = flags;
  fputs("<Swig Packed ", fp); 
  if (SWIG_PackDataName(result, v->pack, v->size, 0, sizeof(result))) {
    fputs("at ", fp); 
    fputs(result, fp); 
  }
  fputs(v->desc,fp); 
  fputs(">", fp);
  return 0; 
}
  
SWIGRUNTIME PyObject *
PySwigPacked_repr(PySwigPacked *v)
{
  char result[SWIG_BUFFER_SIZE];
  if (SWIG_PackDataName(result, v->pack, v->size, 0, sizeof(result))) {
    return PyString_FromFormat("<Swig Packed at %s%s>", result, v->desc);
  } else {
    return PyString_FromFormat("<Swig Packed %s>", v->desc);
  }  
}

SWIGRUNTIME PyObject *
PySwigPacked_str(PySwigPacked *v)
{
  char result[SWIG_BUFFER_SIZE];
  if (SWIG_PackDataName(result, v->pack, v->size, 0, sizeof(result))){
    return PyString_FromFormat("%s%s", result, v->desc);
  } else {
    return PyString_FromFormat("%s", v->desc);
  }  
}

SWIGRUNTIME int
PySwigPacked_compare(PySwigPacked *v, PySwigPacked *w)
{
  int c = strcmp(v->desc, w->desc);
  if (c) {
    return (c > 0) ? 1 : -1;
  } else {
    size_t i = v->size;
    size_t j = w->size;
    int s = (i < j) ? -1 : ((i > j) ? 1 : 0);
    return s ? s : strncmp((char *)v->pack, (char *)w->pack, 2*v->size);
  }
}

SWIGRUNTIME void
PySwigPacked_dealloc(PySwigPacked *self)
{
  free(self->pack);
  PyObject_DEL(self);
}

SWIGRUNTIME PyTypeObject*
PySwigPacked_type(void) {
  static char pyswigpacked_type__doc__[] = 
    "Swig object carries a C/C++ instance pointer";
  static PyTypeObject pyswigpacked_type
#if !defined(__cplusplus)
  ;
  static int type_init = 0;  
  if (!type_init) {
    PyTypeObject tmp
#endif
    = {
    PyObject_HEAD_INIT(&PyType_Type)
    0,					/*ob_size*/
    (char *)"PySwigPacked",		/*tp_name*/
    sizeof(PySwigPacked),		/*tp_basicsize*/
    0,					/*tp_itemsize*/
    /* methods */
    (destructor)PySwigPacked_dealloc,	/*tp_dealloc*/
#if PY_VERSION_HEX < 0x03080000
    (printfunc)PySwigPacked_print,	/*tp_print*/
#else
    0,          /*tp_vectorcall_offset*/
#endif
    (getattrfunc)0,			/*tp_getattr*/
    (setattrfunc)0,			/*tp_setattr*/
    (cmpfunc)PySwigPacked_compare,	/*tp_compare*/
    (reprfunc)PySwigPacked_repr,	/*tp_repr*/
    0,	                                /*tp_as_number*/
    0,					/*tp_as_sequence*/
    0,					/*tp_as_mapping*/
    (hashfunc)0,			/*tp_hash*/
    (ternaryfunc)0,			/*tp_call*/
    (reprfunc)PySwigPacked_str,		/*tp_str*/
    /* Space for future expansion */
    0,0,0,0,
    pyswigpacked_type__doc__, 	        /* Documentation string */
#if PY_VERSION_HEX >= 0x02000000
    0,                                  /* tp_traverse */
    0,                                  /* tp_clear */
#endif
#if PY_VERSION_HEX >= 0x02010000
    0,                                  /* tp_richcompare */
    0,                                  /* tp_weaklistoffset */
#endif
#if PY_VERSION_HEX >= 0x02020000         
    0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, /* tp_iter -> tp_weaklist */
#endif
#if PY_VERSION_HEX >= 0x02030000
    0,                                  /* tp_del */
#endif
#if PY_VERSION_HEX >= 0x02060000
    0,                                  /* tp_version_tag */
#endif
#ifdef COUNT_ALLOCS
    0,0,0,0                             /* tp_alloc -> tp_next */
#endif
    };
#if !defined(__cplusplus)
    pyswigpacked_type = tmp;
    type_init = 1;
  }
#endif
  return &pyswigpacked_type;
}

SWIGRUNTIME PyObject *
PySwigPacked_FromDataAndDesc(void *ptr, size_t size, const char *desc)
{
  PySwigPacked *self = PyObject_NEW(PySwigPacked, PySwigPacked_type());
  if (self == NULL) {
    return NULL;
  } else {
    void *pack = malloc(size);
    if (pack) {
      memcpy(pack, ptr, size);
      self->pack = pack;
      self->desc = desc;
      self->size = size;
      return (PyObject *) self;
    }
    return NULL;
  }
}

SWIGRUNTIMEINLINE const char *
PySwigPacked_UnpackData(PyObject *obj, void *ptr, size_t size)
{
  PySwigPacked *self = (PySwigPacked *)obj;
  if (self->size != size) return 0;
  memcpy(ptr, self->pack, size);
  return self->desc;
}

SWIGRUNTIMEINLINE const char *
PySwigPacked_GetDesc(PyObject *self)
{
  return ((PySwigPacked *)self)->desc;
}

SWIGRUNTIMEINLINE int
PySwigPacked_Check(PyObject *op) {
  return ((op)->ob_type == PySwigPacked_type()) 
    || (strcmp((op)->ob_type->tp_name,"PySwigPacked") == 0);
}

#else
/* -----------------------------------------------------------------------------
 * Use the old Python PyCObject instead of PySwigObject
 * ----------------------------------------------------------------------------- */

#define PySwigObject_GetDesc(obj)	           PyCObject_GetDesc(obj)
#define PySwigObject_Check(obj)	           PyCObject_Check(obj)
#define PySwigObject_AsVoidPtr(obj)	   PyCObject_AsVoidPtr(obj)
#define PySwigObject_FromVoidPtrAndDesc(p, d)  PyCObject_FromVoidPtrAndDesc(p, d, NULL)

#endif

#endif

/* -----------------------------------------------------------------------------
 * errors manipulation
 * ----------------------------------------------------------------------------- */

SWIGRUNTIME void
SWIG_Python_TypeError(const char *type, PyObject *obj)
{
  if (type) {
#if defined(SWIG_COBJECT_TYPES)
    if (obj && PySwigObject_Check(obj)) {
      const char *otype = (const char *) PySwigObject_GetDesc(obj);
      if (otype) {
	PyErr_Format(PyExc_TypeError, "a '%s' is expected, 'PySwigObject(%s)' is received",
		     type, otype);
	return;
      }
    } else 
#endif      
    {
      const char *otype = (obj ? obj->ob_type->tp_name : 0); 
      if (otype) {
	PyObject *str = PyObject_Str(obj);
	const char *cstr = str ? PyString_AsString(str) : 0;
	if (cstr) {
	  PyErr_Format(PyExc_TypeError, "a '%s' is expected, '%s(%s)' is received",
		       type, otype, cstr);
	} else {
	  PyErr_Format(PyExc_TypeError, "a '%s' is expected, '%s' is received",
		       type, otype);
	}
	Py_XDECREF(str);
	return;
      }
    }   
    PyErr_Format(PyExc_TypeError, "a '%s' is expected", type);
  } else {
    PyErr_Format(PyExc_TypeError, "unexpected type is received");
  }
}

SWIGRUNTIMEINLINE void
SWIG_Python_NullRef(const char *type)
{
  if (type) {
    PyErr_Format(PyExc_TypeError, "null reference of type '%s' was received",type);
  } else {
    PyErr_Format(PyExc_TypeError, "null reference was received");
  }
}

SWIGRUNTIME int
SWIG_Python_AddErrMesg(const char* mesg, int infront)
{
  if (PyErr_Occurred()) {
    PyObject *type = 0;
    PyObject *value = 0;
    PyObject *traceback = 0;
    PyErr_Fetch(&type, &value, &traceback);
    if (value) {
      PyObject *old_str = PyObject_Str(value);
      Py_XINCREF(type);
      PyErr_Clear();
      if (infront) {
	PyErr_Format(type, "%s %s", mesg, PyString_AsString(old_str));
      } else {
	PyErr_Format(type, "%s %s", PyString_AsString(old_str), mesg);
      }
      Py_DECREF(old_str);
    }
    return 1;
  } else {
    return 0;
  }
}

SWIGRUNTIME int
SWIG_Python_ArgFail(int argnum)
{
  if (PyErr_Occurred()) {
    /* add information about failing argument */
    char mesg[256];
    PyOS_snprintf(mesg, sizeof(mesg), "argument number %d:", argnum);
    return SWIG_Python_AddErrMesg(mesg, 1);
  } else {
    return 0;
  }
}


/* -----------------------------------------------------------------------------
 * pointers/data manipulation
 * ----------------------------------------------------------------------------- */

/* Convert a pointer value */
SWIGRUNTIME int
SWIG_Python_ConvertPtr(PyObject *obj, void **ptr, swig_type_info *ty, int flags) {
  swig_cast_info *tc;
  const char *c = 0;
  static PyObject *SWIG_this = 0;
  int    newref = 0;
  PyObject  *pyobj = 0;
  void *vptr;
  
  if (!obj) return 0;
  if (obj == Py_None) {
    *ptr = 0;
    return 0;
  }

#ifdef SWIG_COBJECT_TYPES
  if (!(PySwigObject_Check(obj))) {
    if (!SWIG_this)
      SWIG_this = PyString_FromString("this");
    pyobj = obj;
    obj = PyObject_GetAttr(obj,SWIG_this);
    newref = 1;
    if (!obj) goto type_error;
    if (!PySwigObject_Check(obj)) {
      Py_DECREF(obj);
      goto type_error;
    }
  }  
  vptr = PySwigObject_AsVoidPtr(obj);
  c = (const char *) PySwigObject_GetDesc(obj);
  if (newref) { Py_DECREF(obj); }
  goto type_check;
#else
  if (!(PyString_Check(obj))) {
    if (!SWIG_this)
      SWIG_this = PyString_FromString("this");
    pyobj = obj;
    obj = PyObject_GetAttr(obj,SWIG_this);
    newref = 1;
    if (!obj) goto type_error;
    if (!PyString_Check(obj)) {
      Py_DECREF(obj);
      goto type_error;
    }
  } 
  c = PyString_AS_STRING(obj);
  /* Pointer values must start with leading underscore */
  c = SWIG_UnpackVoidPtr(c, &vptr, ty->name);
  if (newref) { Py_DECREF(obj); }
  if (!c) goto type_error;
#endif

type_check:
  if (ty) {
    tc = SWIG_TypeCheck(c,ty);
    if (!tc) goto type_error;
    *ptr = SWIG_TypeCast(tc,vptr);
  } else {
    *ptr = vptr;
  }
  if ((pyobj) && (flags & SWIG_POINTER_DISOWN)) {
    PyObject_SetAttrString(pyobj,(char*)"thisown",Py_False);
  }
  return 0;

type_error:
  PyErr_Clear();
  if (pyobj && !obj) {    
    obj = pyobj;
    if (PyCFunction_Check(obj)) {
      /* here we get the method pointer for callbacks */
      const char *doc = (((PyCFunctionObject *)obj) -> m_ml -> ml_doc);
      c = doc ? strstr(doc, "swig_ptr: ") : 0;
      if (c) {
	c = ty ? SWIG_UnpackVoidPtr(c + 10, &vptr, ty->name) : 0;
	if (!c) goto type_error;
	goto type_check;
      }
    }
  }
  if (flags & SWIG_POINTER_EXCEPTION) {
    if (ty) {
      SWIG_Python_TypeError(SWIG_TypePrettyName(ty), obj);
    } else {
      SWIG_Python_TypeError("C/C++ pointer", obj);
    }
  }
  return -1;
}

/* Convert a pointer value, signal an exception on a type mismatch */
SWIGRUNTIME void *
SWIG_Python_MustGetPtr(PyObject *obj, swig_type_info *ty, int argnum, int flags) {
  void *result;
  if (SWIG_Python_ConvertPtr(obj, &result, ty, flags) == -1) {
    PyErr_Clear();
    if (flags & SWIG_POINTER_EXCEPTION) {
      SWIG_Python_TypeError(SWIG_TypePrettyName(ty), obj);
      SWIG_Python_ArgFail(argnum);
    }
  }
  return result;
}

/* Convert a packed value value */
SWIGRUNTIME int
SWIG_Python_ConvertPacked(PyObject *obj, void *ptr, size_t sz, swig_type_info *ty, int flags) {
  swig_cast_info *tc;
  const char *c = 0;

#if defined(SWIG_COBJECT_TYPES) && !defined(SWIG_COBJECT_PYTHON)
  c = PySwigPacked_UnpackData(obj, ptr, sz);
#else
  if ((!obj) || (!PyString_Check(obj))) goto type_error;
  c = PyString_AS_STRING(obj);
  /* Pointer values must start with leading underscore */
  c = SWIG_UnpackDataName(c, ptr, sz, ty->name);
#endif
  if (!c) goto type_error;
  if (ty) {
    tc = SWIG_TypeCheck(c,ty);
    if (!tc) goto type_error;
  }
  return 0;

type_error:
  PyErr_Clear();
  if (flags & SWIG_POINTER_EXCEPTION) {
    if (ty) {
      SWIG_Python_TypeError(SWIG_TypePrettyName(ty), obj);
    } else {
      SWIG_Python_TypeError("C/C++ packed data", obj);
    }
  }
  return -1;
}  

/* Create a new array object */
SWIGRUNTIME PyObject *
SWIG_Python_NewPointerObj(void *ptr, swig_type_info *type, int own) {
  PyObject *robj = 0;
  if (!type) {
    if (!PyErr_Occurred()) {
      PyErr_Format(PyExc_TypeError, "Swig: null type passed to NewPointerObj");
    }
    return robj;
  }
  if (!ptr) {
    Py_INCREF(Py_None);
    return Py_None;
  }
#ifdef SWIG_COBJECT_TYPES
  robj = PySwigObject_FromVoidPtrAndDesc((void *) ptr, (char *)type->name);
#else
  {
    char result[SWIG_BUFFER_SIZE];
    robj = SWIG_PackVoidPtr(result, ptr, type->name, sizeof(result)) ?
      PyString_FromString(result) : 0;
  }
#endif
  if (!robj || (robj == Py_None)) return robj;
  if (type->clientdata) {
    PyObject *inst;
    PyObject *args = Py_BuildValue((char*)"(O)", robj);
    Py_DECREF(robj);
    inst = PyObject_CallObject((PyObject *) type->clientdata, args);
    Py_DECREF(args);
    if (inst) {
      if (own) {
        PyObject_SetAttrString(inst,(char*)"thisown",Py_True);
      }
      robj = inst;
    }
  }
  return robj;
}

SWIGRUNTIME PyObject *
SWIG_Python_NewPackedObj(void *ptr, size_t sz, swig_type_info *type) {
  PyObject *robj = 0;
  if (!ptr) {
    Py_INCREF(Py_None);
    return Py_None;
  }
#if defined(SWIG_COBJECT_TYPES) && !defined(SWIG_COBJECT_PYTHON)
  robj = PySwigPacked_FromDataAndDesc((void *) ptr, sz, (char *)type->name);
#else
  {
    char result[SWIG_BUFFER_SIZE];
    robj = SWIG_PackDataName(result, ptr, sz, type->name, sizeof(result)) ?
      PyString_FromString(result) : 0;
  }
#endif
  return robj;
}

/* -----------------------------------------------------------------------------*
 *  Get type list 
 * -----------------------------------------------------------------------------*/

#ifdef SWIG_LINK_RUNTIME
void *SWIG_ReturnGlobalTypeList(void *);
#endif

SWIGRUNTIME swig_module_info *
SWIG_Python_GetModule(void) {
  static void *type_pointer = (void *)0;
  /* first check if module already created */
  if (!type_pointer) {
#ifdef SWIG_LINK_RUNTIME
    type_pointer = SWIG_ReturnGlobalTypeList((void *)0);
#else
    type_pointer = PyCObject_Import((char*)"swig_runtime_data" SWIG_RUNTIME_VERSION,
				    (char*)"type_pointer" SWIG_TYPE_TABLE_NAME);
    if (PyErr_Occurred()) {
      PyErr_Clear();
      type_pointer = (void *)0;
    }
  }
#endif
  return (swig_module_info *) type_pointer;
}

SWIGRUNTIME void
SWIG_Python_SetModule(swig_module_info *swig_module) {
  static PyMethodDef swig_empty_runtime_method_table[] = { {NULL, NULL, 0, NULL} };/* Sentinel */

  PyObject *module = Py_InitModule((char*)"swig_runtime_data" SWIG_RUNTIME_VERSION,
				   swig_empty_runtime_method_table);
  PyObject *pointer = PyCObject_FromVoidPtr((void *) swig_module, NULL);
  if (pointer && module) {
    PyModule_AddObject(module, (char*)"type_pointer" SWIG_TYPE_TABLE_NAME, pointer);
  }
}

#ifdef __cplusplus
}
#endif

/* -----------------------------------------------------------------------------*
   Standard SWIG API for use inside user code.
 
   Don't include this file directly, run the command
   swig -python -external-runtime
   Also, read the Modules chapter of the SWIG Manual.
 
 * -----------------------------------------------------------------------------*/

#ifdef SWIG_MODULE_CLIENTDATA_TYPE

SWIGRUNTIMEINLINE swig_type_info *
SWIG_TypeQuery(SWIG_MODULE_CLIENTDATA_TYPE clientdata, const char *name) {
  swig_module_info *module = SWIG_GetModule(clientdata);
  return SWIG_TypeQueryModule(module, module, name);
}

SWIGRUNTIMEINLINE swig_type_info *
SWIG_MangledTypeQuery(SWIG_MODULE_CLIENTDATA_TYPE clientdata, const char *name) {
  swig_module_info *module = SWIG_GetModule(clientdata);
  return SWIG_MangledTypeQueryModule(module, module, name);
}

#else

SWIGRUNTIMEINLINE swig_type_info *
SWIG_TypeQuery(const char *name) {
  swig_module_info *module = SWIG_GetModule(NULL);
  return SWIG_TypeQueryModule(module, module, name);
}

SWIGRUNTIMEINLINE swig_type_info *
SWIG_MangledTypeQuery(const char *name) {
  swig_module_info *module = SWIG_GetModule(NULL);
  return SWIG_MangledTypeQueryModule(module, module, name);
}

#endif

