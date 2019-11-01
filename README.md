__________
## Motivation:

Main motivation for **eswitch** was to overcome **native switch** limitations:

- one parameter per **native switch**
- the parameter restricted to only _integral_ types( **int**, **char**, **enum** ... ).

**eswitch** supports any number of _parameters_ and almost without restriction on their _type_,<br/>
 except that _type_ has to be **comparable**( i.e. must have **operator==** and  **operator!=** ).
__________
## Based on:
implementation of **switch** in **Swift**, in particular:

- **break** is *implicit*, while
-  **fallthrough** is *explicit*.<br/>
____________________________________________________
## Feature comparison:

</br>

| Feature | eswitch | native switch |
| :---: | :---: | :---: |
| *fallthrough* | yes | yes |
| *break* | yes | yes |
| *default*| yes | yes |
| *return* | yes | yes |
| _**or** cmp_ | yes| yes |
| _**and** cmp_ | yes | no |
| _(params > 1) per **eswitch**_ | yes | no |
| _(conditions > 1) per **case**_ | yes | no |

</br>

____________________________________________________
# Examples:

## _implicit break_
``` cpp
    ...
    enum Place { washington, california, ... };
    Place place = washington;

    eswitch( place ) >>
        case_( washington ) >> []{ Print('w'); } >>
        case_( california ) >> []{ Print('c'); } >>
        default_            >> []{ Print('?'); };
```
-  #### Output:
    ```
    w
    ```
## _explicit fallthrough_
``` cpp
    ...
    enum Place { washington, california, ... };
    Place place = washington;

    eswitch( place ) >>
        case_( washington ) >> []{ Print('w'); } >> fallthrough_ >>
        case_( california ) >> []{ Print('c'); } >>
        default_            >> []{ Print('?'); };
```
-  #### Output:
```
    w
    c
```
## _stringify enum_
``` cpp
    ...
    enum Place { washington, california, new_york, ... };
    Place place = new_york;

    const char * enum_to_str = 
        eswitch( place ) >>
            case_( washington ) >> to_return( "washington" ) >>
            case_( california ) >> to_return( "california" ) >>
            case_( new_york )   >> to_return( "new_york" ) >>
            default_            >> to_return( "???" ) >>
            in_place_return_;

    printf( "State=%s" "\n", enum_to_str );
```
-  #### Output:
```
    State=new_york
```

## _multiple conditions and params_
``` cpp
    ...
    enum payload_type { XML, JSON, ... };
    ...
    payload_type payload = ...;
    XmlJsonParser * parser = ...;

    eswitch( payload, parser ) >>
        case_( _1 == XML && _2 != nullptr ) >> [&] { 
            auto result = parser->parse_xml( ... );
            ...
        } >>
        case_( _1 == JSON && _2 != nullptr ) >> [&] {
            auto result = parser->parse_json( ... );
            ...
        } >>
        case_( _2 == nullptr ) >> [&] { 
            PrintError(...); 
        } >>
        default_ >> [] { 
            unreachable(); 
        };
```
## _Params match by predicate_
``` cpp
    int isalpha( int ){...}
    int isdigit( int ){...}
    ...
    int amountAlphas = 0;
    int amountDigits = 0;
    int amountOthers = 0;

    for( const char ch : "Nimbus 2000!"_s ) 
    {    
        eswitch( ch ) >>
            case_( ( isalpha, _1 ) ) >> [&]{ ++amountAlphas; } >>
            case_( ( isdigit, _1 ) ) >> [&]{ ++amountDigits; } >>
            default_                 >> [&]{ ++amountOthers; };
    }

    printf( "amountAlphas=%d, amountDigits=%d, amountOthers=%d", 
        amountAlphas, amountDigits, amountOthers );

```
-  #### Output:
```
    amountAlphas=6, amountDigits=4, amountOthers=2
```

## _Customized cases_
``` cpp

    regex operator "" _r( const char* rgx, size_t ){...}

    // "RegexMatcher" defined in example/example17.cpp
    CUSTOM_EXTENTION( regex, RegexMatcher );
    ...
    string response =
        "HTTP/1.1 200 OK" "\r\n"
        "Content-Lenght: 88" "\r\n"
        "Content-Type: text/html" "\r\n";

    map< string, string > fields;

    for( const auto & line : tokenize( response, "\r\n" ) )
    {       
        eswitch( line ) >>
            case_( "^.+ 200 .+$"_r ) >> // match for "HTTP/1.1 200 OK"
            case_( "^.+: .+$"_r ) >> [&] // match for "key: value"
            { 
                auto splitted = split( line, ':' );                     
                fields[ splitted[ 0 ] ] = splitted[ 1 ];
            } >>
            default_ >> []{ terminate(); } >>
            in_place_return_;
        ...
    }
    ...
    Print( "ContentLength=%s, ContentType=%s", 
        fields[ "Content-Lenght"_s ].c_str(),
        fields[ "Content-Type"_s ].c_str() );

```
-  #### Output:
```
    ContentLength=88, ContentType=text/html
```
_______________

## Minimum C++ standard:
C++14
_______________

## Supported Compilers:

Should work on all major compilers which support **C++14**.<br/>
I personally tested on following:

- **clang** 8 (or later)
- **GCC** 6.3.0 (or later)
- **Visual Studio** **2019**.

_______________
## Performance:

**TOOL TO MEASURE:** google benchmark

**FILE:** */benchmarks/eswitch_benchmark.cpp*

**COMPILERS:** clang-8, gcc-6.3.0 and visual studio 2019.

**BUILD FLAGS:**

- **clang-8** and **gcc-6.3.0** => **"-O3"**
- **visual studio 2019** => **"/Ox"**.
	
**RESULTS:**

- **clang-8**   - no performance difference. 
- **gcc-6.3.0** - no performance difference.
- **visual studio 2019** - *slower*, but **not critical**.
_______________

## How to build:

**release:** *./build.sh < compiler_name >* // where compiler_name=**clang++|g++|...**, but *not* **clang|gcc**.

**debug:**  *./build_dev.sh < compiler_name >*
_______________
## License:
Boost Software License( Version 1.0 )
_______________

