//  Copyright (c) 2019 Rustam Abdumalikov
//
//  "eswitch_v4" library
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

#include "eswitch_v4.hpp"
#include "gtest/gtest.h"
#include <memory>
#include <sstream>

enum Place { unknown = 0, new_york=5, washington=129, new_jersey=501 };

TEST(eswitch_v4_case, one_condition_1st_param_EQUAL)
{
    using namespace eswitch_v4;

    bool executed = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 == washington ) >> [&](){ executed = true; };
    
    ASSERT_EQ(executed, true );
}

TEST(eswitch_v4_case, one_condition_2nd_param_EQUAL)
{
    using namespace eswitch_v4;

    bool executed = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _2 == new_jersey ) >> [&](){ executed = true; };
    
    ASSERT_EQ(executed, true );
}

TEST(eswitch_v4_case, one_condition_3rd_param_EQUAL)
{
    using namespace eswitch_v4;

    bool executed = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _3 == new_york ) >> [&](){ executed = true; };
    
    ASSERT_EQ(executed, true );
}

TEST(eswitch_v4_case, one_condition_1st_param_NOT_EQUAL)
{
    using namespace eswitch_v4;

    bool executed = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 != new_jersey ) >> [&](){ executed = true; };
    
    ASSERT_EQ(executed, true );
}

TEST(eswitch_v4_case, one_condition_2nd_param_NOT_EQUAL)
{
    using namespace eswitch_v4;

    bool executed = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _2 != washington ) >> [&](){ executed = true; };
    
    ASSERT_EQ(executed, true );
}

TEST(eswitch_v4_case, one_condition_3rd_param_NOT_EQUAL)
{
    using namespace eswitch_v4;

    bool executed = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _3 != new_jersey ) >> [&](){ executed = true; };
    
    ASSERT_EQ(executed, true );
}


TEST(eswitch_v4_case, two_condition_1st_and_2nd_param_EQUAL_via_AND)
{
    using namespace eswitch_v4;

    bool executed = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 == washington && _2 == new_jersey ) >> [&](){ executed = true; };
    
    ASSERT_EQ(executed, true );
}

TEST(eswitch_v4_case, two_condition_2nd_and_1st_param_EQUAL_via_AND)
{
    using namespace eswitch_v4;

    bool executed = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _2 == new_jersey && _1 == washington ) >> [&](){ executed = true; };
    
    ASSERT_EQ(executed, true );
}

TEST(eswitch_v4_case, two_condition_1st_and_3rd_param_EQUAL_via_AND)
{
    using namespace eswitch_v4;

    bool executed = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 == washington && _3 == new_york ) >> [&](){ executed = true; };
    
    ASSERT_EQ(executed, true );
}

TEST(eswitch_v4_case, two_condition_3rd_and_1st_param_EQUAL_via_AND)
{
    using namespace eswitch_v4;

    bool executed = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _3 == new_york  && _1 == washington ) >> [&](){ executed = true; };
    
    ASSERT_EQ(executed, true );
}

TEST(eswitch_v4_case, two_condition_2nd_and_3rd_param_EQUAL_via_AND)
{
    using namespace eswitch_v4;

    bool executed = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _2 == new_jersey && _3 == new_york ) >> [&](){ executed = true; };
    
    ASSERT_EQ(executed, true );
}

TEST(eswitch_v4_case, two_condition_3rd_and_2nd_param_EQUAL_via_AND)
{
    using namespace eswitch_v4;

    bool executed = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _3 == new_york && _2 == new_jersey ) >> [&](){ executed = true; };
    
    ASSERT_EQ(executed, true );
}

TEST(eswitch_v4_case, two_condition_1st_and_2nd_param_EQUAL_via_OR_first_true )
{
    using namespace eswitch_v4;

    bool executed = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 == washington || _2 == new_york ) >> [&](){ executed = true; };
    
    ASSERT_EQ(executed, true );
}

TEST(eswitch_v4_case, two_condition_1st_and_2nd_param_EQUAL_via_OR_second_true )
{
    using namespace eswitch_v4;

    bool executed = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 == new_york || _2 == new_jersey ) >> [&](){ executed = true; };
    
    ASSERT_EQ(executed, true );
}

TEST(eswitch_v4_case, two_condition_1st_and_3rd_param_EQUAL_via_OR_first_true )
{
    using namespace eswitch_v4;

    bool executed = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 == washington || _3 == new_jersey ) >> [&](){ executed = true; };
    
    ASSERT_EQ(executed, true );
}

TEST(eswitch_v4_case, two_condition_1st_and_3rd_param_EQUAL_via_OR_second_true )
{
    using namespace eswitch_v4;

    bool executed = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 == new_jersey || _3 == new_york ) >> [&](){ executed = true; };
    
    ASSERT_EQ(executed, true );
}

TEST(eswitch_v4_case, two_condition_2nd_and_3rd_param_EQUAL_via_OR_first_true )
{
    using namespace eswitch_v4;

    bool executed = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _2 == new_jersey || _3 == washington ) >> [&](){ executed = true; };
    
    ASSERT_EQ(executed, true );
}

TEST(eswitch_v4_case, two_condition_2nd_and_3rd_param_EQUAL_via_OR_second_true )
{
    using namespace eswitch_v4;

    bool executed = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _2 == washington || _3 == new_york ) >> [&](){ executed = true; };
    
    ASSERT_EQ(executed, true );
}


TEST(eswitch_v4_case, 3_cases_1st_true )
{
    using namespace eswitch_v4;

    bool executed = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 == washington ) >> [&](){ executed = true; }
        >> case_( _2 == washington ) >> [&](){ FAIL(); }
        >> case_( _3 == washington ) >> [&](){ FAIL(); };
    
    ASSERT_EQ(executed, true );
}

TEST(eswitch_v4_case, 3_cases_2nd_true )
{
    using namespace eswitch_v4;

    bool executed = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 == new_jersey ) >> [&](){ FAIL(); }
        >> case_( _2 == new_jersey ) >> [&](){ executed = true; }
        >> case_( _3 == new_jersey ) >> [&](){ FAIL(); };
    
    ASSERT_EQ(executed, true );
}

TEST(eswitch_v4_case, 3_cases_3rd_true )
{
    using namespace eswitch_v4;

    bool executed = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 == new_york ) >> [&](){ FAIL(); }
        >> case_( _2 == new_york ) >> [&](){ FAIL(); }
        >> case_( _3 == new_york ) >> [&](){ executed = true; };
    
    ASSERT_EQ(executed, true );
}

TEST(eswitch_v4_case, 3_complex_cases_1st_true )
{
    using namespace eswitch_v4;

    bool executed = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 == washington && _2 == new_jersey && _3 == new_york ) >> [&](){ executed = true; }
        >> case_( _1 == washington || _2 == new_jersey || _3 == new_york ) >> [&](){ FAIL(); }
        >> case_( _1 != washington && _2 != new_jersey && _3 != new_york ) >> [&](){ FAIL(); };
    
    ASSERT_EQ(executed, true );
}

TEST(eswitch_v4_case, 3_complex_cases_2nd_true )
{
    using namespace eswitch_v4;

    bool executed = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington && _2 == new_jersey && _3 == new_york ) >> [&](){ FAIL(); }
        >> case_( _1 == washington || _2 == new_jersey || _3 == new_york ) >> [&](){ executed = true; }
        >> case_( _1 != washington && _2 != new_jersey && _3 != new_york ) >> [&](){ FAIL(); };
    
    ASSERT_EQ(executed, true );
}

TEST(eswitch_v4_case, 3_complex_cases_3rd_true )
{
    using namespace eswitch_v4;

    bool executed = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington && _2 == new_jersey && _3 == new_york ) >> [&](){ FAIL(); }
        >> case_( _1 != washington || _2 != new_jersey || _3 != new_york ) >> [&](){ FAIL(); }
        >> case_( _1 == washington && _2 == new_jersey && _3 == new_york ) >> [&](){ executed = true; };
    
    ASSERT_EQ(executed, true );
}

TEST(eswitch_v4_case, all_source_entries_have_different_type )
{
    using namespace eswitch_v4;

    bool executed = false;

    const double value = 2.5;

    eswitch( washington, std::string( "Hello" ), value )
        >> case_( _1 == washington && _2 == "Hello" && _3 == 2.5 ) >> [&](){ executed = true; }
        >> case_( _1 == washington && _2 == "Hello" && _3 == 2.5 ) >> [&](){ FAIL(); };
    
    ASSERT_EQ(executed, true );
}

TEST(eswitch_v4_case, any_from )
{
    using namespace eswitch_v4;

    bool executed = false;

    eswitch( washington ) >> 
        case_( any_from( washington, new_jersey, new_york ) ) >> [&](){ executed = true; } >>
        default_ >> []{ FAIL(); };

    ASSERT_EQ(executed, true );
}

TEST(eswitch_v4_case, any_from_with_string )
{
    using namespace eswitch_v4;

    bool executed = false;

    eswitch( std::string{"h++"} ) >> 
        case_( any_from( "cpp", "cc", "c++", "cxx", "C" ) ) >> [&]{ FAIL(); } >>
        case_( any_from( "h", "hpp", "hh", "h++", "hxx", "H" ) ) >> [&]{ executed = true; } >>
        default_ >> []{ FAIL(); };

    ASSERT_EQ(executed, true );
}

TEST(eswitch_v4_case, any_from_with_lvalue_int )
{
    using namespace eswitch_v4;

    bool executed = false;

    int i = 10;
    int j = 20;
    int k = 26;
    int d = 155;

    eswitch( 20 ) >> 
        case_( any_from( i, j ) ) >> [&]{ executed = true; } >>
        case_( any_from( k, d ) ) >> [&]{ FAIL(); } >>
        default_ >> []{ FAIL(); };

    ASSERT_EQ(executed, true );
}

TEST(eswitch_v4_case, 1st_match_not_equal_any_from )
{
    using namespace eswitch_v4;

    bool executed = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 != any_from( new_jersey, new_york ) ) >> [&](){ executed = true; }
        >> case_( _2 == any_from( washington, new_jersey, new_york ) ) >> [&](){ FAIL(); }
        >> case_( _3 == any_from( washington, new_jersey, new_york ) ) >> [&](){ FAIL(); };
    
    ASSERT_EQ(executed, true );
}

TEST(eswitch_v4_case, 2nd_match_not_equal_any_from )
{
    using namespace eswitch_v4;

    bool executed = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 == any_from( new_jersey, new_york ) ) >> [&](){ FAIL(); }
        >> case_( _2 != any_from( washington, new_york ) ) >> [&](){ executed = true; }
        >> case_( _3 == any_from( washington, new_jersey, new_york ) ) >> [&](){ FAIL(); };
    
    ASSERT_EQ(executed, true );
}

TEST(eswitch_v4_case, 3rd_match_not_equal_any_from )
{
    using namespace eswitch_v4;

    bool executed = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 == any_from( new_jersey, new_york ) ) >> [&](){ FAIL(); }
        >> case_( _2 == any_from( washington, new_york ) ) >> [&](){ FAIL(); }
        >> case_( _3 != any_from( washington, new_jersey ) ) >> [&](){ executed = true; };
    
    ASSERT_EQ(executed, true );
}

TEST(eswitch_v4_case, 1st_match_any_from )
{
    using namespace eswitch_v4;

    bool executed = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 == any_from( washington, new_jersey, new_york ) ) >> [&](){ executed = true; }
        >> case_( _2 == any_from( washington, new_jersey, new_york ) ) >> [&](){ FAIL(); }
        >> case_( _3 == any_from( washington, new_jersey, new_york ) ) >> [&](){ FAIL(); };
    
    ASSERT_EQ(executed, true );
}

TEST(eswitch_v4_case, 2nd_match_any_from )
{
    using namespace eswitch_v4;

    bool executed = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 != any_from( washington, new_jersey, new_york ) ) >> [&](){ FAIL(); }
        >> case_( _2 == any_from( washington, new_jersey, new_york ) ) >> [&](){ executed = true; }
        >> case_( _3 == any_from( washington, new_jersey, new_york ) ) >> [&](){ FAIL(); };
    
    ASSERT_EQ(executed, true );
}

TEST(eswitch_v4_case, 3rd_match_any_from )
{
    using namespace eswitch_v4;

    bool executed = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 != any_from( washington, new_jersey, new_york ) ) >> [&](){ FAIL(); }
        >> case_( _2 != any_from( washington, new_jersey, new_york ) ) >> [&](){ FAIL(); }
        >> case_( _3 == any_from( washington, new_jersey, new_york ) ) >> [&](){ executed = true; };
    
    ASSERT_EQ(executed, true );
}

TEST(eswitch_v4_case, default_match_any_from )
{
    using namespace eswitch_v4;

    bool executed = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 != any_from( washington, new_jersey, new_york ) ) >> [&](){ FAIL(); }
        >> case_( _2 != any_from( washington, new_jersey, new_york ) ) >> [&](){ FAIL(); }
        >> case_( _3 != any_from( washington, new_jersey, new_york ) ) >> [&](){ FAIL(); }
        >> default_ >> [&](){ executed = true; };
    
    ASSERT_EQ(executed, true );
}

struct index_value 
{
    int i; 
    friend bool operator==( const index_value& lhv, const index_value& rhv ) { return lhv.i == rhv.i; }
    friend bool operator==( const index_value& lhv, const int rhv ) { return lhv.i == rhv; }    
    friend bool operator!=( const index_value& lhv, const index_value& rhv ) { return lhv.i != rhv.i; }
    friend bool operator!=( const index_value& lhv, const int rhv ) { return lhv.i != rhv; }    
};

TEST(eswitch_v4_case, all_source_entries_have_different_type_1_is_custom )
{
    using namespace eswitch_v4;

    bool executed_case_1 = false;
    bool executed_case_2 = false;

    ASSERT_EQ( index_value{ 10 }, index_value{ 10 } );
    ASSERT_EQ( index_value{ 10 }, 10 );
   
    std::vector< int > arg1{ 1, 2 };
    std::string arg2{ "Hello" };
    index_value arg3{ 10 };

    eswitch( arg1, arg2, arg3 )
      >> case_( _1 == std::vector< int >{ 1, 2 } && _2 == "Hello" && _3 == index_value{ 10 } ) >> [&](){ executed_case_1 = true; } >> fallthrough_
      >> case_( _1 == std::vector< int >{ 1, 2 } && _2 == "Hello" && _3 == 10 ) >> [&](){ executed_case_2 = true; };
    
    ASSERT_EQ(executed_case_1, true );
    ASSERT_EQ(executed_case_2, true );
}

TEST(eswitch_v4_implicit_break, 1st_case_true_other_inaccessable )
{
    using namespace eswitch_v4;

    bool executed = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 == washington ) >> [&](){ executed = true; }
        >> case_( _1 == washington ) >> [&](){ FAIL(); }
        >> case_( _1 == washington ) >> [&](){ FAIL(); };
    
    ASSERT_EQ(executed, true );
}

TEST(eswitch_v4_implicit_break, 2nd_case_true_other_inaccessable )
{
    using namespace eswitch_v4;

    bool executed = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 == new_jersey ) >> [&](){ FAIL(); }
        >> case_( _2 == new_jersey ) >> [&](){ executed = true; }
        >> case_( _3 == new_jersey ) >> [&](){ FAIL(); };
    
    ASSERT_EQ(executed, true );
}

TEST(eswitch_v4_implicit_break, 3rd_case_true_other_inaccessable )
{
    using namespace eswitch_v4;

    bool executed = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 == new_york ) >> [&](){ FAIL(); }
        >> case_( _2 == new_york ) >> [&](){ FAIL(); }
        >> case_( _3 == new_york ) >> [&](){ executed = true; }
        >> default_ >> [&](){ FAIL(); };
    
    ASSERT_EQ(executed, true );
}






TEST(eswitch_v4_default, none_of_cases_valid_thus_DEFAULT )
{
    using namespace eswitch_v4;

    bool executed = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington ) >> [&](){ FAIL(); }
        >> case_( _2 != new_jersey ) >> [&](){ FAIL(); }
        >> case_( _3 != new_york ) >> [&](){ FAIL(); }
        >> default_ >> [&](){ executed = true; };
    
    ASSERT_EQ(executed, true );
}

TEST(eswitch_v4_fallthrought, 1st_match_fallthrought_to_2nd )
{
    using namespace eswitch_v4;

    bool executed_1_case = false;
    bool executed_2_case = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 == washington ) >> [&](){ executed_1_case = true; } >> fallthrough_
        >> case_( _2 == new_jersey ) >> [&](){ executed_2_case = true; }
        >> case_( _3 == new_york )   >> [&](){ FAIL(); }
        >> default_                  >> [&](){ FAIL(); };
    
    ASSERT_EQ(executed_1_case, true );
    ASSERT_EQ(executed_2_case, true );
}

TEST(eswitch_v4_fallthrought, 2nd_match_fallthrought_to_3rd )
{
    using namespace eswitch_v4;

    bool executed_1_case = false;
    bool executed_2_case = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington ) >> [&](){ FAIL(); }
        >> case_( _2 == new_jersey ) >> [&](){ executed_1_case = true; } >> fallthrough_
        >> case_( _3 == new_york )   >> [&](){ executed_2_case = true; }
        >> default_                  >> [&](){ FAIL(); };
    
    ASSERT_EQ(executed_1_case, true );
    ASSERT_EQ(executed_2_case, true );
}

TEST(eswitch_v4_fallthrought, 3rd_match_fallthrought_to_DEFAULT_ )
{
    using namespace eswitch_v4;

    bool executed_1_case = false;
    bool executed_2_case = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington ) >> [&](){ FAIL(); }
        >> case_( _2 != new_jersey ) >> [&](){ FAIL(); }
        >> case_( _3 == new_york )   >> [&](){ executed_1_case = true; } >> fallthrough_
        >> default_                  >> [&](){ executed_2_case = true; };
    
    ASSERT_EQ(executed_1_case, true );
    ASSERT_EQ(executed_2_case, true );
}


TEST(eswitch_v4_return, 1st_match_and_to_return_one_statement )
{
    using namespace eswitch_v4;

    Place actual_result = unknown;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 == washington ) >> to_return( washington )
        >> case_( _2 == new_jersey ) >> [&](){ return new_jersey; }
        >> case_( _3 == new_york )   >> [&](){ return new_york; }
        >> default_ >> [](){ FAIL(); }
        >> handle_return( [&]( const auto & res ){ actual_result = res; } );
    
    ASSERT_EQ(actual_result, washington );
}

TEST(eswitch_v4_return, 2nd_match_and_to_return_one_statement )
{
    using namespace eswitch_v4;

    Place actual_result = unknown;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington ) >> to_return( washington )
        >> case_( _2 == new_jersey ) >> to_return( new_jersey )
        >> case_( _3 == new_york )   >> [&](){ return new_york; }
        >> default_ >> [](){ FAIL(); }
        >> handle_return( [&]( const auto & res ){ actual_result = res; } );
    
    ASSERT_EQ(actual_result, new_jersey );
}

TEST(eswitch_v4_return, 3rd_match_and_to_return_one_statement )
{
    using namespace eswitch_v4;

    Place actual_result = unknown;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington ) >> to_return( washington )
        >> case_( _2 != new_jersey ) >> to_return( new_jersey )
        >> case_( _3 == new_york )   >> to_return( new_york )
        >> default_ >> [](){ FAIL(); }
        >> handle_return( [&]( const auto & res ){ actual_result = res; } );
    
    ASSERT_EQ(actual_result, new_york );
}

TEST(eswitch_v4_return, 1st_match_to_return_plus_in_place_return )
{
    using namespace eswitch_v4;

    Place actual_result = eswitch( washington, new_jersey, new_york )
        >> case_( _1 == washington ) >> to_return( washington )
        >> case_( _2 == new_jersey ) >> to_return( new_jersey )
        >> case_( _3 == new_york )   >> to_return( new_york )
        >> default_ >> [](){ FAIL(); }
        >> in_place_return_;
    
    ASSERT_EQ(actual_result, washington );
}

TEST(eswitch_v4_return, 2nd_match_to_return_plus_in_place_return )
{
    using namespace eswitch_v4;

    Place actual_result = eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington ) >> to_return( washington )
        >> case_( _2 == new_jersey ) >> to_return( new_jersey )
        >> case_( _3 == new_york )   >> to_return( new_york )
        >> default_ >> [](){ FAIL(); }
        >> in_place_return_;
    
    ASSERT_EQ(actual_result, new_jersey );
}

TEST(eswitch_v4_return, 3rd_match_to_return_plus_in_place_return )
{
    using namespace eswitch_v4;

    Place actual_result = eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington ) >> to_return( washington )
        >> case_( _2 != new_jersey ) >> to_return( new_jersey )
        >> case_( _3 == new_york )   >> to_return( new_york )
        >> default_ >> [](){ FAIL(); }
        >> in_place_return_;
    
    ASSERT_EQ(actual_result, new_york );
}

TEST(eswitch_v4_return, 1st_match_to_return_plus_in_place_return_const_char )
{
    using namespace eswitch_v4;

    const char* actual_result = eswitch( washington, new_jersey, new_york )
        >> case_( _1 == washington ) >> to_return( "washington" )
        >> case_( _2 == new_jersey ) >> to_return( "new_jersey" )
        >> case_( _3 == new_york )   >> to_return( "new_york" )
        >> default_ >> [](){ FAIL(); }
        >> in_place_return_;
    
    ASSERT_EQ(actual_result, std::string( "washington" ) );
}

TEST(eswitch_v4_return, 2nd_match_to_return_plus_in_place_return_const_char )
{
    using namespace eswitch_v4;

    const char* actual_result = eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington ) >> to_return( "washington" )
        >> case_( _2 == new_jersey ) >> to_return( "new_jersey" )
        >> case_( _3 == new_york )   >> to_return( "new_york" )
        >> default_ >> [](){ FAIL(); }
        >> in_place_return_;
    
    ASSERT_EQ(actual_result, std::string( "new_jersey" ) );
}

TEST(eswitch_v4_return, 3rd_match_to_return_plus_in_place_return_const_char )
{
    using namespace eswitch_v4;

    const char* actual_result = eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington ) >> to_return( "washington" )
        >> case_( _2 != new_jersey ) >> to_return( "new_jersey" )
        >> case_( _3 == new_york )   >> to_return( "new_york" )
        >> default_ >> [](){ FAIL(); }
        >> in_place_return_;
    
    ASSERT_EQ(actual_result, std::string( "new_york" ) );
}



TEST(eswitch_v4_return, 1st_match_to_return_plus_in_place_return_dynamic_int_array )
{
    using namespace eswitch_v4;

    std::unique_ptr< int > actual_result( eswitch( washington, new_jersey, new_york )
        >> case_( _1 == washington ) >> to_return( new int(10) )
        >> case_( _2 == new_jersey ) >> to_return( nullptr )
        >> case_( _3 == new_york )   >> to_return( nullptr )
        >> default_ >> [](){ FAIL(); }
        >> in_place_return_ );
    
    EXPECT_TRUE(actual_result != nullptr );
}

TEST(eswitch_v4_return, 2nd_match_to_return_plus_in_place_return_dynamic_int_array )
{
    using namespace eswitch_v4;

    std::unique_ptr< int > actual_result( eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington ) >> to_return( nullptr )
        >> case_( _2 == new_jersey ) >> to_return( new int(10) )
        >> case_( _3 == new_york )   >> to_return( nullptr )
        >> default_ >> [](){ FAIL(); }
        >> in_place_return_ );
    
    EXPECT_TRUE(actual_result != nullptr );
}

TEST(eswitch_v4_return, 3rd_match_to_return_plus_in_place_return_dynamic_int_array )
{
    using namespace eswitch_v4;

    std::unique_ptr< int > actual_result( 
        eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington ) >> to_return( nullptr )
        >> case_( _2 != new_jersey ) >> to_return( new int(10) )
        >> case_( _3 == new_york )   >> to_return( nullptr )
        >> default_ >> [](){ FAIL(); }
        >> in_place_return_ );
    
    EXPECT_TRUE(actual_result == nullptr );
}

TEST(eswitch_v4_in_place_return, 1st_match_lambda_return_conversion_from_const_char_ptr_to_std_string )
{
    using namespace eswitch_v4;

    std::string actual_result( 
        eswitch( washington, new_jersey, new_york )
        >> case_( _1 == washington ) >> []{ return "hello"; }
        >> case_( _2 == new_jersey ) >> []{ return std::string( "world" ); }
        >> in_place_return_ );
    
    ASSERT_EQ( actual_result, "hello" );
}

TEST(eswitch_v4_in_place_return, 2nd_match_lambda_return_conversion_from_const_char_ptr_to_std_string )
{
    using namespace eswitch_v4;

    std::string actual_result( 
        eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington ) >> []{ return "hello"; }
        >> case_( _2 == new_jersey ) >> []{ return std::string( "world" ); }
        >> in_place_return_ );
    
    EXPECT_TRUE(actual_result == "world" );
}

TEST(eswitch_v4_in_place_return, 1st_match_to_lambda_return_plus_in_place_return_dynamic_int_array )
{
    using namespace eswitch_v4;

    std::unique_ptr< int > actual_result( eswitch( washington, new_jersey, new_york )
        >> case_( _1 == washington ) >> []{ return new int(10); }
        >> case_( _2 == new_jersey ) >> []{ return nullptr; }
        >> case_( _3 == new_york )   >> []{ return nullptr; }
        >> in_place_return_ );
    
    EXPECT_TRUE(actual_result != nullptr );
}

TEST(eswitch_v4_in_place_return, 2nd_match_to_lambda_return_plus_in_place_return_dynamic_int_array )
{
    using namespace eswitch_v4;

    std::unique_ptr< int > actual_result( eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington ) >> []{ return nullptr; }
        >> case_( _2 == new_jersey ) >> []{ return new int(10); }
        >> case_( _3 == new_york )   >> []{ return nullptr; }
        >> in_place_return_ );
    
    EXPECT_TRUE(actual_result != nullptr );
}

TEST(eswitch_v4_in_place_return, 3rd_match_to_lambda_return_plus_in_place_return_dynamic_int_array )
{
    using namespace eswitch_v4;

    std::unique_ptr< int > actual_result( 
        eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington ) >> []{ return nullptr; }
        >> case_( _2 != new_jersey ) >> []{ return new int(10); }
        >> case_( _3 == new_york )   >> []{ return nullptr; }
        >> in_place_return_ );
    
    EXPECT_TRUE(actual_result == nullptr );
}

TEST(eswitch_v4_in_place_return, 1st_match_return_conversion_from_const_char_ptr_to_std_string )
{
    using namespace eswitch_v4;

    std::string actual_result( 
        eswitch( washington, new_jersey, new_york )
        >> case_( _1 == washington ) >> to_return( "hello" )
        >> case_( _2 == new_jersey ) >> to_return( std::string( "world" ) )
        >> in_place_return_ );
    
    EXPECT_TRUE(actual_result == "hello" );
}

TEST(eswitch_v4_in_place_return, 2nd_match_return_conversion_from_const_char_ptr_to_std_string )
{
    using namespace eswitch_v4;

    std::string actual_result( 
        eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington ) >> to_return( "hello" )
        >> case_( _2 == new_jersey ) >> to_return( std::string( "world" ) )
        >> in_place_return_ );
   
    EXPECT_TRUE(actual_result == "world" );
}


struct base
{ 
    virtual ~base() = default; 
    virtual int foo() { return 10; }
};

struct derived : public base
{
     virtual int foo() override { return 20; }
};

TEST(eswitch_v4_return, 1st_match_return_conversion_from_base_to_base )
{
    using namespace eswitch_v4;

    std::unique_ptr< base > actual_result( 
        eswitch( washington, new_jersey, new_york )
        >> case_( _1 == washington ) >> to_return( new base() )
        >> case_( _2 == new_jersey ) >> to_return( new derived() )
        >> in_place_return_ );
    
    ASSERT_EQ( actual_result->foo(), 10 );
}

TEST(eswitch_v4_return, 2nd_match_return_conversion_from_derived_to_base )
{
    using namespace eswitch_v4;

    std::unique_ptr< base > actual_result( 
        eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington ) >> to_return( new base() )
        >> case_( _2 == new_jersey ) >> to_return( new derived() )
        >> in_place_return_ );
    
    ASSERT_EQ( actual_result->foo(), 20 );
}

TEST(eswitch_v4_return, 3rd_match_return_conversion_from_nullptr_to_base )
{
    using namespace eswitch_v4;

    std::unique_ptr< base > actual_result( 
        eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington ) >> to_return( new base() )
        >> case_( _2 != new_jersey ) >> to_return( new derived() )
        >> case_( _3 == new_york )   >> to_return( nullptr )
        >> in_place_return_ );
    
    EXPECT_TRUE( actual_result == nullptr );
}

TEST(eswitch_v4_return, 1st_match_return_conversion_from_base_to_base_reverse )
{
    using namespace eswitch_v4;

    std::unique_ptr< base > actual_result( 
        eswitch( washington, new_jersey, new_york )
        >> case_( _2 == new_jersey ) >> to_return( new derived() )
        >> case_( _1 == washington ) >> to_return( new base() )
        >> in_place_return_ );
    
    ASSERT_EQ( actual_result->foo(), 20 );
}

TEST(eswitch_v4_return, 2nd_match_return_conversion_from_derived_to_base_reverse )
{
    using namespace eswitch_v4;

    std::unique_ptr< base > actual_result( 
        eswitch( washington, new_jersey, new_york )
        >> case_( _2 != new_jersey ) >> to_return( new derived() )
        >> case_( _1 == washington ) >> to_return( new base() )
        >> in_place_return_ );
    
    ASSERT_EQ( actual_result->foo(), 10 );
}

TEST(eswitch_v4_return, 3rd_match_return_conversion_from_nullptr_to_base_reverse )
{
    using namespace eswitch_v4;

    std::unique_ptr< base > actual_result( 
        eswitch( washington, new_jersey, new_york )
        >> case_( _2 != new_jersey ) >> to_return( new derived() )
        >> case_( _1 != washington ) >> to_return( new base() )
        >> case_( _3 == new_york )   >> to_return( nullptr )
        >> in_place_return_ );
    
    EXPECT_TRUE( actual_result == nullptr );
}

TEST(eswitch_v4_return, 23rd_match_return_conversion_from_nullptr_to_base_reverse )
{
    using namespace eswitch_v4;

    std::unique_ptr< base > actual_result( 
        eswitch( washington, new_jersey, new_york )
        >> case_( _3 != new_york )   >> to_return( nullptr )
        >> case_( _2 != new_jersey ) >> to_return( new derived() )
        >> case_( _1 == washington ) >> to_return( new base() )
        >> in_place_return_ );
    
    EXPECT_TRUE( actual_result != nullptr );
    EXPECT_TRUE( actual_result->foo() == 10 );
}
struct custom
{
    custom() = default;
    custom( int i ) : i( i ){}
    int i;
};

TEST(eswitch_v4_return, 1st_match_no_default_ctor_at_return_type )
{
    using namespace eswitch_v4;

    auto actual_result( 
        eswitch( washington, new_jersey, new_york )
        >> case_( _1 == washington ) >> to_return( custom( 1 ) )
        >> case_( _2 == new_jersey ) >> to_return( custom( 2 ) )
        >> case_( _3 == new_york )   >> to_return( custom( 3 ) )
        >> in_place_return_ );
    
    ASSERT_EQ( actual_result.i, 1 );
}

TEST(eswitch_v4_return, 2nd_match_no_default_ctor_at_return_type )
{
    using namespace eswitch_v4;

    auto actual_result( 
        eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington ) >> to_return( custom( 1 ) )
        >> case_( _2 == new_jersey ) >> to_return( custom( 2 ) )
        >> case_( _3 == new_york )   >> to_return( custom( 3 ) )
        >> in_place_return_ );
    
    ASSERT_EQ( actual_result.i, 2 );
}

TEST(eswitch_v4_return, 3rd_match_no_default_ctor_at_return_type )
{
    using namespace eswitch_v4;

    auto actual_result( 
        eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington ) >> to_return( custom( 1 ) )
        >> case_( _2 != new_jersey ) >> to_return( custom( 2 ) )
        >> case_( _3 == new_york )   >> to_return( custom( 3 ) )
        >> in_place_return_ );
    
    ASSERT_EQ( actual_result.i, 3 );
}


TEST(eswitch_v4_return, 1st_match_non_copyable_at_return_type_unique_ptr )
{
    using namespace eswitch_v4;

    auto actual_result( 
        eswitch( washington, new_jersey, new_york )
        >> case_( _1 == washington ) >> to_return( std::make_unique< int >( 10 ) )
        >> case_( _2 == new_jersey ) >> to_return( nullptr )
        >> case_( _3 == new_york )   >> to_return( nullptr )
        >> in_place_return_ );

   EXPECT_TRUE( actual_result != nullptr );    
   EXPECT_TRUE( *actual_result == 10 );
}

TEST(eswitch_v4_return, return_just_nullptr )
{
    using namespace eswitch_v4;

    auto actual_result( 
        eswitch( washington, new_jersey, new_york )
        >> case_( _2 == new_jersey ) >> to_return( nullptr )
        >> in_place_return_ );

   EXPECT_TRUE( actual_result == nullptr );
}
TEST(eswitch_v4_return, 1st_match_non_copyable_at_return_type )
{
    using namespace eswitch_v4;

    auto actual_result( 
        eswitch( washington, new_jersey, new_york )
        >> case_( _2 == new_jersey ) >> to_return( nullptr )
        >> case_( _1 == washington ) >> to_return( std::make_unique< int >( 10 ) )
        >> case_( _3 == new_york )   >> to_return( nullptr )
        >> in_place_return_ );

   EXPECT_TRUE( actual_result == nullptr );
}


TEST(eswitch_v4_in_place_return, 1st_match_lambda_return_conversion_from_base_to_base )
{
    using namespace eswitch_v4;

    std::unique_ptr< base > actual_result( 
        eswitch( washington, new_jersey, new_york )
        >> case_( _1 == washington ) >> []{ return new base(); }
        >> case_( _2 == new_jersey ) >> []{ return new derived(); }
        >> in_place_return_ );
    
    ASSERT_EQ( actual_result->foo(), 10 );
}

TEST(eswitch_v4_in_place_return, 2nd_match_lambda_return_conversion_from_derived_to_base )
{
    using namespace eswitch_v4;

    std::unique_ptr< base > actual_result( 
        eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington ) >> []{ return new base(); }
        >> case_( _2 == new_jersey ) >> []{ return new derived(); }
        >> in_place_return_ );
    
    ASSERT_EQ( actual_result->foo(), 20 );
}

TEST(eswitch_v4_in_place_return, 3rd_match_lambda_return_conversion_from_nullptr_to_base )
{
    using namespace eswitch_v4;

    std::unique_ptr< base > actual_result( 
        eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington ) >> []{ return new base(); }
        >> case_( _2 != new_jersey ) >> []{ return new derived(); }
        >> case_( _3 == new_york )   >> []{ return nullptr; }
        >> in_place_return_ );
    
    EXPECT_TRUE( actual_result == nullptr );
}


TEST(eswitch_v4_return, 1st_match_and_return )
{
    using namespace eswitch_v4;

    Place actual_result = unknown;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 == washington ) >> [&](){ return washington; }
        >> case_( _2 == new_jersey ) >> [&](){ return new_jersey; }
        >> case_( _3 == new_york )   >> [&](){ return new_york; }
        >> default_ >> [](){ FAIL(); }
        >> handle_return( [&]( const auto & res ){ actual_result = res; } );
    
    ASSERT_EQ(actual_result, washington );
}

TEST(eswitch_v4_return, 2nd_match_and_return )
{
    using namespace eswitch_v4;

    Place actual_result = unknown;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington ) >> [&](){ return washington; }
        >> case_( _2 == new_jersey ) >> [&](){ return new_jersey; }
        >> case_( _3 == new_york )   >> [&](){ return new_york; }
        >> default_ >> [](){ FAIL(); }
        >> handle_return( [&]( const auto & res ){ actual_result = res; } );
    
    ASSERT_EQ(actual_result, new_jersey );
}

TEST(eswitch_v4_return, 3rd_match_and_return )
{
    using namespace eswitch_v4;

    Place actual_result = unknown;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington ) >> [&](){ return washington; }
        >> case_( _2 != new_jersey ) >> [&](){ return new_jersey; }
        >> case_( _3 == new_york )   >> [&](){ return new_york; }
        >> default_ >> [](){ FAIL(); }
        >> handle_return( [&]( const auto & res ){ actual_result = res; } );
    
    ASSERT_EQ(actual_result, new_york );
}

TEST(eswitch_v4_return, default_match_and_return )
{
    using namespace eswitch_v4;

    Place actual_result = new_jersey;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington ) >> [&](){ return washington; }
        >> case_( _2 != new_jersey ) >> [&](){ return new_jersey; }
        >> case_( _3 != new_york )   >> [&](){ return new_york; }
        >> default_ >> [](){ return unknown; }
        >> handle_return( [&]( const auto & res ){ actual_result = res; } );
    
    ASSERT_EQ(actual_result, unknown );
}

TEST(eswitch_v4_return, with_cases_just_default_match_and_return )
{
    using namespace eswitch_v4;

    Place actual_result = new_jersey;

    eswitch( washington, new_jersey, new_york )
        >> default_ >> [](){ return unknown; }
        >> handle_return( [&]( const auto & res ){ actual_result = res; } );
    
    ASSERT_EQ(actual_result, unknown );
}

TEST(eswitch_v4_return, 1st_match_regardless_fallthrough )
{
    using namespace eswitch_v4;

    Place actual_result = new_jersey;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 == washington ) >> [&](){ return washington; } >> fallthrough_
        >> case_( _2 == new_jersey ) >> [&](){ return new_jersey; } >> fallthrough_
        >> case_( _3 == new_york )   >> [&](){ return new_york; }   >> fallthrough_
        >> default_ >> [](){ return unknown; }
        >> handle_return( [&]( const auto & res ){ actual_result = res; } );
    
    ASSERT_EQ(actual_result, washington );
}

TEST(eswitch_v4_return, 2nd_match_regardless_fallthrough )
{
    using namespace eswitch_v4;

    Place actual_result = new_jersey;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington ) >> [&](){ return washington; } >> fallthrough_
        >> case_( _2 == new_jersey ) >> [&](){ return new_jersey; } >> fallthrough_
        >> case_( _3 == new_york )   >> [&](){ return new_york; }   >> fallthrough_
        >> default_ >> [](){ return unknown; }
        >> handle_return( [&]( const auto & res ){ actual_result = res; } );
    
    ASSERT_EQ(actual_result, new_jersey );
}

TEST(eswitch_v4_return, 3rd_match_regardless_fallthrough )
{
    using namespace eswitch_v4;

    Place actual_result = new_jersey;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington ) >> [&](){ return washington; } >> fallthrough_
        >> case_( _2 != new_jersey ) >> [&](){ return new_jersey; } >> fallthrough_
        >> case_( _3 == new_york )   >> [&](){ return new_york; }   >> fallthrough_
        >> default_ >> [](){ return unknown; }
        >> handle_return( [&]( const auto & res ){ actual_result = res; } );
    
    ASSERT_EQ(actual_result, new_york );
}

TEST(eswitch_v4_return, 1st_match_cases_with_and_without_return )
{
    using namespace eswitch_v4;

    Place actual_result = unknown;

    bool executed = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 == washington ) >> [&](){ executed = true; }
        >> case_( _2 == new_jersey ) >> [&](){ return new_jersey; }
        >> case_( _3 == new_york )   >> [&](){ return new_york; }
        >> default_ >> [](){ FAIL(); }
        >> handle_return( [&]( const auto & res ){ actual_result = res; } );

    ASSERT_EQ(executed, true );
    ASSERT_EQ(actual_result, unknown );
}

TEST(eswitch_v4_return, 2nd_match_cases_with_and_without_return )
{
    using namespace eswitch_v4;

    Place actual_result = unknown;

    bool executed = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington ) >> [&](){ return washington; }
        >> case_( _2 == new_jersey ) >> [&](){ executed = true; }
        >> case_( _3 == new_york )   >> [&](){ return new_york; }
        >> default_ >> [](){ FAIL(); }
        >> handle_return( [&]( const auto & res ){ actual_result = res; } );

    ASSERT_EQ(executed, true );
    ASSERT_EQ(actual_result, unknown );
}

TEST(eswitch_v4_return, 3rd_match_cases_with_and_without_return )
{
    using namespace eswitch_v4;

    Place actual_result = unknown;

    bool executed = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington ) >> [&](){ return washington; }
        >> case_( _2 != new_jersey ) >> [&](){ return new_jersey; }
        >> case_( _3 == new_york )   >> [&](){ executed = true; }
        >> default_ >> [](){ FAIL(); }
        >> handle_return( [&]( const auto & res ){ actual_result = res; } );

    ASSERT_EQ(executed, true );
    ASSERT_EQ(actual_result, unknown );
}

TEST(eswitch_v4_return, default_match_cases_with_and_without_return )
{
    using namespace eswitch_v4;

    Place actual_result = unknown;

    bool executed = false;

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington ) >> [&](){ return washington; }
        >> case_( _2 != new_jersey ) >> [&](){ return new_jersey; }
        >> case_( _3 != new_york )   >> [&](){ return new_york; }
        >> default_ >> [&](){ executed = true; }
        >> handle_return( [&]( const auto & res ){ actual_result = res; } );

    ASSERT_EQ(executed, true );
    ASSERT_EQ(actual_result, unknown );
}




TEST(eswitch_v4_return_in_place, 1st_match_and_return )
{
    using namespace eswitch_v4;

    Place actual_result = eswitch( washington, new_jersey, new_york )
        >> case_( _1 == washington ) >> [&](){ return washington; }
        >> case_( _2 == new_jersey ) >> [&](){ return new_jersey; }
        >> case_( _3 == new_york )   >> [&](){ return new_york; }
        >> default_ >> [](){ FAIL(); }
        >> in_place_return_;
    
    ASSERT_EQ(actual_result, washington );
}

TEST(eswitch_v4_return_in_place, 2nd_match_and_return )
{
    using namespace eswitch_v4;

    Place actual_result = eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington ) >> [&](){ return washington; }
        >> case_( _2 == new_jersey ) >> [&](){ return new_jersey; }
        >> case_( _3 == new_york )   >> [&](){ return new_york; }
        >> default_ >> [](){ FAIL(); }
        >> in_place_return_;
    
    ASSERT_EQ(actual_result, new_jersey );
}

TEST(eswitch_v4_return_in_place, 3rd_match_and_return )
{
    using namespace eswitch_v4;

    Place actual_result = eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington ) >> [&](){ return washington; }
        >> case_( _2 != new_jersey ) >> [&](){ return new_jersey; }
        >> case_( _3 == new_york )   >> [&](){ return new_york; }
        >> default_ >> [](){ FAIL(); }
        >> in_place_return_;
    
    ASSERT_EQ(actual_result, new_york );
}

TEST(eswitch_v4_return_in_place, default_match_and_return )
{
    using namespace eswitch_v4;

    Place actual_result = eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington ) >> [&](){ return washington; }
        >> case_( _2 != new_jersey ) >> [&](){ return new_jersey; }
        >> case_( _3 != new_york )   >> [&](){ return new_york; }
        >> default_ >> [](){ return unknown; }
        >> in_place_return_;
    
    ASSERT_EQ(actual_result, unknown );
}

TEST(eswitch_v4_return_in_place, no_match_and_exception )
{
    using namespace eswitch_v4;

    bool executed = false;
    try
    {
    Place actual_result = eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington ) >> [&](){ return washington; }
        >> case_( _2 != new_jersey ) >> [&](){ return new_jersey; }
        >> case_( _3 != new_york )   >> [&](){ return new_york; }
        >> in_place_return_;

        FAIL();

    } catch( const std::logic_error & le )
    {
        executed = true;
    }

    ASSERT_EQ( executed, true );
    
}

TEST(eswitch_v4_return_in_place, 1st_match_regardless_fallthrough )
{
    using namespace eswitch_v4;

    Place actual_result = eswitch( washington, new_jersey, new_york )
        >> case_( _1 == washington ) >> [&](){ return washington; } >> fallthrough_
        >> case_( _2 == new_jersey ) >> [&](){ return new_jersey; } >> fallthrough_
        >> case_( _3 == new_york )   >> [&](){ return new_york; }   >> fallthrough_
        >> default_ >> [](){ return unknown; }
        >> in_place_return_;
    
    ASSERT_EQ(actual_result, washington );
}

TEST(eswitch_v4_return_in_place, 2nd_match_regardless_fallthrough )
{
    using namespace eswitch_v4;

    Place actual_result = eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington ) >> [&](){ return washington; } >> fallthrough_
        >> case_( _2 == new_jersey ) >> [&](){ return new_jersey; } >> fallthrough_
        >> case_( _3 == new_york )   >> [&](){ return new_york; }   >> fallthrough_
        >> default_ >> [](){ return unknown; }
        >> in_place_return_;
    
    ASSERT_EQ(actual_result, new_jersey );
}

TEST(eswitch_v4_return_in_place, 3rd_match_regardless_fallthrough )
{
    using namespace eswitch_v4;

    Place actual_result = eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington ) >> [&](){ return washington; } >> fallthrough_
        >> case_( _2 != new_jersey ) >> [&](){ return new_jersey; } >> fallthrough_
        >> case_( _3 == new_york )   >> [&](){ return new_york; }   >> fallthrough_
        >> default_ >> [](){ return unknown; }
        >> in_place_return_;
    
    ASSERT_EQ(actual_result, new_york );
}

TEST(eswitch_v4_return_in_place, 1st_match_cases_with_and_without_return )
{
    using namespace eswitch_v4;

    bool executed_catch = false;
    bool executed_case = false;

    try { 
    auto actual_result = eswitch( washington, new_jersey, new_york )
        >> case_( _1 == washington ) >> [&](){ executed_case = true; }
        >> case_( _2 == new_jersey ) >> [&](){ return new_jersey; }
        >> case_( _3 == new_york )   >> [&](){  }
        >> default_ >> [](){ FAIL(); }
        >> in_place_return_;
        
        FAIL();
    } catch( const std::logic_error & le )
    {
        executed_catch = true;
    }

    ASSERT_EQ(executed_case, true );
    ASSERT_EQ(executed_catch, true );
}

TEST(eswitch_v4_return_in_place, 2nd_match_cases_with_and_without_return )
{
    using namespace eswitch_v4;

    bool executed_catch = false;
    bool executed_case = false;

    try { 
    auto actual_result = eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington ) >> [&](){ return washington; }
        >> case_( _2 == new_jersey ) >> [&](){ executed_case = true; }
        >> case_( _3 == new_york )   >> [&](){  }
        >> default_ >> [](){ FAIL(); }
        >> in_place_return_;
        
        FAIL();
    } catch( const std::logic_error & le )
    {
        executed_catch = true;
    }

    ASSERT_EQ(executed_case, true );
    ASSERT_EQ(executed_catch, true );
}

TEST(eswitch_v4_return_in_place, 3rd_match_cases_with_and_without_return )
{
    using namespace eswitch_v4;

    bool executed_catch = false;
    bool executed_case = false;

    try { 
    auto actual_result = eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington ) >> [&](){ return washington; }
        >> case_( _2 != new_jersey ) >> [&](){  }
        >> case_( _3 == new_york )   >> [&](){  executed_case = true; }
        >> default_ >> [](){ FAIL(); }
        >> in_place_return_;

        FAIL();
    } catch( const std::logic_error & le )
    {
        executed_catch = true;
    }

    ASSERT_EQ(executed_case, true );
    ASSERT_EQ(executed_catch, true );
}

TEST(eswitch_v4_return_in_place, default_match_cases_with_and_without_return )
{
    using namespace eswitch_v4;

    bool executed_catch = false;
    bool executed_case = false;

    try{
    auto actual_result = eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington ) >> [&](){ return washington; }
        >> case_( _2 != new_jersey ) >> [&](){  }
        >> case_( _3 != new_york )   >> [&](){  }
        >> default_ >> [&](){ executed_case = true; }
        >> in_place_return_;

        FAIL();
    } catch( const std::logic_error & le )
    {
        executed_catch = true;
    }

    ASSERT_EQ(executed_case, true );
    ASSERT_EQ(executed_catch, true );
}










TEST(eswitch_v4_predicate, rvalue_lambda )
{
    using namespace eswitch_v4;

    bool executed = false;
    
    eswitch( washington, new_jersey, new_york )
        >> case_( _1 == washington ) >> [&](){ executed = true; };
    
    ASSERT_EQ(executed, true );
}

TEST(eswitch_v4_predicate, rvalue_lambda_and_return )
{
    using namespace eswitch_v4;

    bool executed = false;
    
    auto result = eswitch( washington, new_jersey, new_york )
        >> case_( _1 == washington ) >> [&](){ executed = true; return "washington"; } >> in_place_return_;
    
    ASSERT_EQ( executed, true );
    ASSERT_EQ( result, std::string{ "washington" } );
}

TEST(eswitch_v4_predicate, lvalue_lambda )
{
    using namespace eswitch_v4;

    bool executed = false;
    
    auto handler = [&](){ executed = true; };

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 == washington ) >> handler;
    
    ASSERT_EQ(executed, true );
}

TEST(eswitch_v4_predicate, after_default )
{
    using namespace eswitch_v4;

    bool executed = false;
    
    auto handler = [&](){ executed = true; };

    eswitch( washington, new_jersey, new_york )
        >> case_( _1 != washington ) >> []{ FAIL(); } >>
        default_ >> handler;
    
    ASSERT_EQ(executed, true );
}

TEST(eswitch_v4_predicate, lvalue_lambda_and_return )
{
    using namespace eswitch_v4;

    bool executed = false;
    
    auto handler = [&](){ executed = true; return "washington"; };

    auto result = eswitch( washington, new_jersey, new_york )
        >> case_( _1 == washington ) >> handler >> in_place_return_;
    
    ASSERT_EQ( executed, true );
    ASSERT_EQ( result, std::string{ "washington" } );
}

TEST(eswitch_v4_any, not_equal )
{
    using namespace eswitch_v4;
    
    EXPECT_TRUE( ( 10 != extension::any() ) == false );
}

TEST(eswitch_v4_any, equal )
{
    using namespace eswitch_v4;
    
    EXPECT_TRUE( ( 10 == extension::any() ) == true );
    EXPECT_TRUE( ( "Hello" == extension::any() ) == true );
    EXPECT_TRUE( ( 'c' == extension::any() ) == true );
    EXPECT_TRUE( ( std::string( "" ) == extension::any() ) == true );
    EXPECT_TRUE( ( std::vector<int>{ 1, 2 } == extension::any() ) == true );
}

TEST(eswitch_v4_return, return_after_fallthrough )
{
    using namespace eswitch_v4;

    auto result = eswitch( washington, new_jersey, new_york ) >> 
        case_( _1 == washington ) >> []{} >> fallthrough_ >> 
        case_( _1 == new_jersey ) >> to_return( new_jersey ) >> 
        in_place_return_;
    
    EXPECT_TRUE( result == new_jersey );
}


TEST(eswitch_v4_return, ternary_operator_eval_first )
{
    using namespace eswitch_v4;

    bool flag = true;

    auto result = eswitch( washington, new_jersey, new_york ) >> 
        case_( _1 == washington ) >> [&]{ return flag ? new_york : unknown; } >> 
        case_( _1 == new_jersey ) >> to_return( new_jersey ) >> 
        in_place_return_;
    
    EXPECT_TRUE( result == new_york );
}


TEST(eswitch_v4_in_place_return, ternary_operator_eval_first )
{
    using namespace eswitch_v4;

    bool flag = true;

    auto result = eswitch( washington, new_jersey, new_york ) >> 
        case_( _1 == washington ) >> to_return( flag ? new_york : unknown ) >> 
        case_( _1 == new_jersey ) >> to_return( new_jersey ) >> 
        in_place_return_;
    
    EXPECT_TRUE( result == new_york );
}


TEST(eswitch_v4_return, ternary_operator_eval_second )
{
    using namespace eswitch_v4;

    bool flag = false;

    auto result = eswitch( washington, new_jersey, new_york ) >> 
        case_( _1 == washington ) >> [&]{ return flag ? new_jersey : washington; } >> 
        case_( _1 == new_jersey ) >> to_return( new_jersey ) >> 
        in_place_return_;
    
    EXPECT_TRUE( result == washington );
}


TEST(eswitch_v4_in_place_return, ternary_operator_eval_second )
{
    using namespace eswitch_v4;

    bool flag = false;

    auto result = eswitch( washington, new_jersey, new_york ) >> 
        case_( _1 == washington ) >> to_return( flag ? new_jersey : washington ) >> 
        case_( _1 == new_jersey ) >> to_return( new_jersey ) >> 
        in_place_return_;
    
    EXPECT_TRUE( result == washington );
}

bool _isNegative = true;
bool _isZero = true;

struct cf
{
    cf( bool first, bool second )
    {
        _isNegative = first;
        _isZero = second;
    }

    bool isZero() { return _isZero; }
    bool isNegative() { return _isNegative; }

};

TEST(eswitch_v4_in_place_return, eval_expression )
{
    using namespace eswitch_v4;

    {
    cf CF( true, true );

    auto result = eswitch( washington, new_jersey, new_york ) >> 
        case_( _1 == washington ) >> to_return( CF.isNegative() && CF.isZero() ) >> 
        in_place_return_;
    
    EXPECT_TRUE( result == true );
    }

    {
    cf CF( false, true );

    auto result = eswitch( washington, new_jersey, new_york ) >> 
        case_( _1 == washington ) >> to_return( CF.isNegative() && CF.isZero() ) >> 
        in_place_return_;
    
    EXPECT_TRUE( result == false );
    }

    {
    cf CF( false, false );

    auto result = eswitch( washington, new_jersey, new_york ) >> 
        case_( _1 == washington ) >> to_return( !CF.isNegative() && !CF.isZero() ) >> 
        in_place_return_;
    
    EXPECT_TRUE( result == true );
    }

    {
    cf CF( true, false );

    auto result = eswitch( washington, new_jersey, new_york ) >> 
        case_( _1 == washington ) >> to_return( CF.isNegative() && !CF.isZero() ) >> 
        in_place_return_;
    
    EXPECT_TRUE( result == true );
    }

    {
    cf CF( true, false );

    auto result = eswitch( washington, new_jersey, new_york ) >> 
        case_( _1 != washington ) >> to_return( CF.isNegative() && !CF.isZero() ) >> 
        case_( _2 == new_jersey ) >> to_return( false ) >>         
        in_place_return_;
    
    EXPECT_TRUE( result == false );
    }
}

TEST(eswitch_v4_return, stringstream_eval_plus_operator_comma )
{
    using namespace eswitch_v4;

    bool flag = false;

    std::stringstream ss;
    
    auto result = eswitch( washington, new_jersey, new_york ) >> 
        case_( _1 == washington ) >> to_return( ( ss << "Hello " << std::to_string( 1 ), ss.str() ) ) >> 
        in_place_return_;
    
    EXPECT_TRUE( result == "Hello 1" );
}

TEST(eswitch_v4_return, bitwise_operation_right_shift )
{
    using namespace eswitch_v4;

    int ch = 0b0000'1111;
    {
    auto result = eswitch( washington, new_jersey, new_york ) >> 
        case_( _1 == washington ) >> to_return( ch >> 1 ) >> 
        in_place_return_;
    
    EXPECT_TRUE( result == 0b0000'0111 );
    }

    {
    auto result = eswitch( washington, new_jersey, new_york ) >> 
        case_( _1 != washington ) >> to_return( ch >> 1 ) >> 
        case_( _2 == new_jersey ) >> to_return( ch >> 3 ) >> 
        in_place_return_;
    
    EXPECT_TRUE( result == 0b0000'0001 );
    }
}

TEST(eswitch_v4_return, bitwise_operation_combination )
{
    using namespace eswitch_v4;

    const int ch = 0b11001000;

    auto result = eswitch( washington, new_jersey, new_york ) >> 
        case_( _1 == washington ) >> to_return( ch ^ 0b10111000 ) >> 
        in_place_return_;
    
    EXPECT_TRUE( result == 0b01110000 );
}

TEST(eswitch_v4_return, long_expression_evaluation )
{
    using namespace eswitch_v4;
    
    std::vector< int > v;

    auto result = eswitch( washington, new_jersey, new_york ) >> 
        case_( _2 == washington ) >>
        case_( _1 == washington ) >> to_return( ( v = std::vector< int >{ 1, 2, 3 }, v.push_back( 4 ), v.push_back( 5 ), v.push_back( 4 ), v ) ) >> 
            in_place_return_;
    
    std::vector< int > expected_result{ 1, 2, 3, 4, 5, 4 };

    EXPECT_TRUE( result == expected_result );
}

TEST(eswitch_v4_case, match_case_without_body_to_interrupt )
{
    using namespace eswitch_v4;
    
    eswitch( washington, new_jersey, new_york ) >> 
        case_( _2 == new_jersey ) >>
        case_( _1 == washington ) >> []{ FAIL(); };
}

#include <cmath>

struct fcmp
{
    double value;
    explicit fcmp( const double input ) : value( input ) {}

    friend bool operator==( const double v, const fcmp cf )
    {
        const double epsilon = 0.0001f;
        return fabs( cf.value - v ) < epsilon;
    }

    friend bool operator!=( const double v, const fcmp cf )
    {
        return !( v == cf );
    }
};

CASE_OVERLOAD( double, fcmp );

TEST(eswitch_v4_case, double_as_param )
{
    using namespace eswitch_v4;
    
    bool executed = false;

    double d = 2.0002;

    eswitch( d ) >> 
        case_( _1 == 2.0001 )   >> []{ FAIL(); } >>
        case_( _1 == 2.0002 ) >> [&]{ executed = true; };

    EXPECT_TRUE( executed );
}

TEST(eswitch_v4_simple_case, double_as_param )
{
    using namespace eswitch_v4;
    
    bool executed = false;

    double d = 2.0002;

    eswitch( d ) >> 
        case_( 2.0007 ) >> []{ FAIL(); } >>
        case_( 2.0002 ) >> [&]{ executed = true; };

    EXPECT_TRUE( executed );
}

TEST(eswitch_v4_simple_case, double_as_param_even_if_second_param_is )
{
    using namespace eswitch_v4;
    
    bool executed = false;

    double d = 2.0002;

    eswitch( d, std::string( "" ) ) >> 
        case_( 2.0007 ) >> []{ FAIL(); } >>
        case_( 2.0002 ) >> [&]{ executed = true; };

    EXPECT_TRUE( executed );
}

TEST(eswitch_v4_simple_case, to_string )
{
    using namespace eswitch_v4;
    {
    Place p = washington;

    const std::string stringify_enum = 
        eswitch( p ) >> 
            case_( washington ) >> to_return("washington") >>
            case_( new_jersey ) >> to_return("new_jersey") >>
            case_( new_york )   >> to_return("new_york") >>
            default_            >> to_return("unknown") >>
        in_place_return_;

    EXPECT_TRUE( stringify_enum == "washington" );
    }
    {
    Place p = new_jersey;

    const std::string stringify_enum = 
        eswitch( p ) >> 
            case_( washington ) >> to_return("washington") >>
            case_( new_jersey ) >> to_return("new_jersey") >>
            case_( new_york )   >> to_return("new_york") >>
            default_            >> to_return("unknown") >>
        in_place_return_;

    EXPECT_TRUE( stringify_enum == "new_jersey" );
    }
    {
    Place p = new_york;

    const std::string stringify_enum = 
        eswitch( p ) >> 
            case_( washington ) >> to_return("washington") >>
            case_( new_jersey ) >> to_return("new_jersey") >>
            case_( new_york )   >> to_return("new_york") >>
            default_            >> to_return("unknown") >>
        in_place_return_;

    EXPECT_TRUE( stringify_enum == "new_york" );
    }
    {
    Place p = unknown;

    const std::string stringify_enum = 
        eswitch( p ) >> 
            case_( washington ) >> to_return("washington") >>
            case_( new_jersey ) >> to_return("new_jersey") >>
            case_( new_york )   >> to_return("new_york") >>
            default_            >> to_return("unknown") >>
        in_place_return_;

    EXPECT_TRUE( stringify_enum == "unknown" );
    }
}

TEST(eswitch_v4_with_predicates, pred_1_true )
{
    using namespace eswitch_v4;

    auto is_odd = []( int i ){ return i % 2 != 0; };

    auto pred_cnd = ( is_odd, _1 );

    EXPECT_TRUE( pred_cnd( std::make_tuple( 1 ) ) );
}

TEST(eswitch_v4_with_predicates, pred_1_false )
{
    using namespace eswitch_v4;

    auto is_odd = []( int i ){ return i % 2 != 0; };

    auto pred_cnd = ( is_odd, _1 );

    EXPECT_TRUE( !pred_cnd( std::make_tuple( 2 ) ) );
}


TEST(eswitch_v4_with_predicates, pred_2_true )
{
    using namespace eswitch_v4;
    

    auto is_non_negative = []( int i, int j ){ return i >= 0 && j >= 0; };

    auto pred_cnd = ( is_non_negative, _2, _1 );
    
    EXPECT_TRUE( pred_cnd( std::make_tuple( 1, 2 ) ) );
}

TEST(eswitch_v4_with_predicates, pred_2_false )
{
    using namespace eswitch_v4;
    

    auto is_non_negative = []( int i, int j ){ return i >= 0 && j >= 0; };

    auto pred_cnd = ( is_non_negative, _2, _1 );
    
    EXPECT_TRUE( !pred_cnd( std::make_tuple( -1, 2 ) ) );
}

TEST(eswitch_v4_with_predicates, ands_true )
{
    using namespace eswitch_v4;
    

    auto is_odd = []( int i ){ return i % 2 != 0; };
    auto is_non_negative = []( int i, int j ){ return i >= 0 && j >= 0; };

    auto pred_cnd = ( is_non_negative, _2, _1 ) && ( is_odd, _1 );
    
    EXPECT_TRUE( pred_cnd( std::make_tuple( 11, 2 ) ) );
}

TEST(eswitch_v4_with_predicates, ands_false_in_1st_condition )
{
    using namespace eswitch_v4;
    

    auto is_odd = []( int i ){ return i % 2 != 0; };
    auto is_non_negative = []( int i, int j ){ return i >= 0 && j >= 0; };

    auto pred_cnd = ( is_non_negative, _2, _1 ) && ( is_odd, _1 );
    
    EXPECT_TRUE( !pred_cnd( std::make_tuple( 11, -2 ) ) );
}

TEST(eswitch_v4_with_predicates, ands_false_in_2nd_condition )
{
    using namespace eswitch_v4;
    

    auto is_odd = []( int i ){ return i % 2 != 0; };
    auto is_non_negative = []( int i, int j ){ return i >= 0 && j >= 0; };

    auto pred_cnd = ( is_non_negative, _2, _1 ) && ( is_odd, _1 );
    
    EXPECT_TRUE( !pred_cnd( std::make_tuple( 12, 2 ) ) );
}

TEST(eswitch_v4_with_predicates, ors_true )
{
    using namespace eswitch_v4;
    

    auto is_odd = []( int i ){ return i % 2 != 0; };
    auto is_non_negative = []( int i, int j ){ return i >= 0 && j >= 0; };

    auto pred_cnd = ( is_non_negative, _2, _1 ) || ( is_odd, _1 );
    
    EXPECT_TRUE( pred_cnd( std::make_tuple( 11, 2 ) ) );
}

TEST(eswitch_v4_with_predicates, ors_false_in_1st_condition )
{
    using namespace eswitch_v4;
    

    auto is_odd = []( int i ){ return i % 2 != 0; };
    auto is_non_negative = []( int i, int j ){ return i >= 0 && j >= 0; };

    auto pred_cnd = ( is_non_negative, _2, _1 ) || ( is_odd, _1 );
    
    EXPECT_TRUE( pred_cnd( std::make_tuple( 3, -3 ) ) );
}

TEST(eswitch_v4_with_predicates, ors_false_in_2nd_condition )
{
    using namespace eswitch_v4;
    

    auto is_odd = []( int i ){ return i % 2 != 0; };
    auto is_non_negative = []( int i, int j ){ return i >= 0 && j >= 0; };

    auto pred_cnd = ( is_non_negative, _2, _1 ) || ( is_odd, _1 );
    
    EXPECT_TRUE( pred_cnd( std::make_tuple( 4, 6 ) ) );
}

TEST(eswitch_v4_with_predicates, ors_false_in_both_conditions )
{
    using namespace eswitch_v4;
    

    auto is_odd = []( int i ){ return i % 2 != 0; };
    auto is_non_negative = []( int i, int j ){ return i >= 0 && j >= 0; };

    auto pred_cnd = ( is_non_negative, _2, _1 ) || ( is_odd, _1 );
    
    EXPECT_TRUE( !pred_cnd( std::make_tuple( -4, -4 ) ) );
}

TEST(eswitch_v4_with_predicates, full_feature_1st_match )
{
    using namespace eswitch_v4;
    

    auto is_odd = []( int i ){ return i % 2 != 0; };
    auto is_non_negative = []( int i, int j ){ return i >= 0 && j >= 0; };
  
    bool executed = false;

    eswitch( 3, 4 ) >>
        case_( ( is_non_negative, _1, _2 ) && ( is_odd, _1 ) ) >> [&]{ executed = true; } >>
        case_( ( is_odd, _1 ) ) >> [&]{ FAIL(); } >>
        case_( ( is_non_negative, _1, _2 ) ) >> [&]{ FAIL(); } >>
        case_( _1 == 3 && _2 == 4 ) >> [&]{ FAIL(); };

    EXPECT_TRUE( executed );
}

TEST(eswitch_v4_with_predicates, full_feature_2nd_match )
{
    using namespace eswitch_v4;
    

    auto is_odd = []( int i ){ return i % 2 != 0; };
    auto is_non_negative = []( int i, int j ){ return i >= 0 && j >= 0; };
  
    bool executed = false;

    eswitch( 3, -4 ) >>
        case_( ( is_non_negative, _1, _2 ) && ( is_odd, _1 ) ) >> [&]{ FAIL(); } >>
        case_( ( is_odd, _1 ) ) >> [&]{ executed = true; } >>
        case_( ( is_non_negative, _1, _2 ) ) >> [&]{ FAIL(); } >>    
        case_( _1 == 3 && _2 == 4 ) >> [&]{ FAIL();};

    EXPECT_TRUE( executed );
}

TEST(eswitch_v4_with_predicates, full_feature_3rd_match )
{
    using namespace eswitch_v4;
    

    auto is_odd = []( int i ){ return i % 2 != 0; };
    auto is_non_negative = []( int i, int j ){ return i >= 0 && j >= 0; };
  
    bool executed = false;

    eswitch( 4, 7 ) >>
        case_( ( is_non_negative, _1, _2 ) && ( is_odd, _1 ) ) >> [&]{ FAIL(); } >>
        case_( ( is_odd, _1 ) ) >> [&]{ FAIL(); } >>
        case_( ( is_non_negative, _1, _2 ) ) >> [&]{ executed = true; } >>    
        case_( _1 == 3 && _2 == 4 ) >> [&]{ FAIL();};

    EXPECT_TRUE( executed );
}

TEST(eswitch_v4_with_predicates, full_feature_4th_match )
{
    using namespace eswitch_v4;
    

    auto is_odd = []( int i ){ return i % 2 != 0; };
    auto is_non_negative = []( int i, int j ){ return i >= 0 && j >= 0; };
  
    bool executed = false;

    eswitch( -2, 4 ) >>
        case_( ( is_non_negative, _1, _2 ) && ( is_odd, _1 ) ) >> [&]{ FAIL(); } >>
        case_( ( is_odd, _1 ) ) >> [&]{ FAIL(); } >>
        case_( ( is_non_negative, _1, _2 ) ) >> [&]{ FAIL(); } >>    
        case_( _1 == -2 && _2 == 4 ) >> [&]{ executed = true; };
        
    EXPECT_TRUE( executed );
}

TEST(eswitch_v4_with_predicates, lambda_full_feature_1st_match )
{
    using namespace eswitch_v4;
    

    auto is_odd = []( int i ){ return i % 2 != 0; };
    auto is_non_negative = []( int i, int j ){ return i >= 0 && j >= 0; };
  
    bool executed = false;

    eswitch( 3, 4 ) >>
        case_( ( []( int i, int j ){ return i >= 0 && j >= 0; }, _1, _2 ) && ( []( int i ){ return i % 2 != 0; }, _1 ) ) >> [&]{ executed = true; } >>
        case_( ( []( int i ){ return i % 2 != 0; }, _1 ) ) >> [&]{ FAIL(); } >>
        case_( ( []( int i, int j ){ return i >= 0 && j >= 0; }, _1, _2 ) ) >> [&]{ FAIL(); } >>    
        case_( _1 == -2 && _2 == 4 ) >> [&]{ FAIL(); };
        
    EXPECT_TRUE( executed );
}

TEST(eswitch_v4_with_predicates, lambda_full_feature_2nd_match )
{
    using namespace eswitch_v4;
    

    auto is_odd = []( int i ){ return i % 2 != 0; };
    auto is_non_negative = []( int i, int j ){ return i >= 0 && j >= 0; };
  
    bool executed = false;

    eswitch( 3, -4 ) >>
        case_( ( []( int i, int j ){ return i >= 0 && j >= 0; }, _1, _2 ) && ( []( int i ){ return i % 2 != 0; }, _1 ) ) >> [&]{ FAIL(); } >>
        case_( ( []( int i ){ return i % 2 != 0; }, _1 ) ) >> [&]{ executed = true; } >>
        case_( ( []( int i, int j ){ return i >= 0 && j >= 0; }, _1, _2 ) ) >> [&]{ FAIL(); } >>    
        case_( _1 == -2 && _2 == 4 ) >> [&]{ FAIL(); };
        
    EXPECT_TRUE( executed );
}

TEST(eswitch_v4_with_predicates, to_return_full_feature_1st_match )
{
    using namespace eswitch_v4;
    

    auto is_odd = []( int i ){ return i % 2 != 0; };
    auto is_non_negative = []( int i, int j ){ return i >= 0 && j >= 0; };
  
    const auto result = eswitch( 3, 4 ) >>
        case_( ( is_non_negative, _1, _2 ) && ( is_odd, _1 ) ) >> to_return( true ) >>
        case_( ( is_odd, _1 ) ) >> to_return( false ) >>
        case_( ( is_non_negative, _1, _2 ) ) >> to_return( false ) >>    
        case_( _1 == -2 && _2 == 4 ) >> to_return( false ) >>
        in_place_return_;
        
    EXPECT_TRUE( result );
}

TEST(eswitch_v4_with_predicates, to_return_full_feature_2nd_match )
{
    using namespace eswitch_v4;
    

    auto is_odd = []( int i ){ return i % 2 != 0; };
    auto is_non_negative = []( int i, int j ){ return i >= 0 && j >= 0; };
  
    const auto result = eswitch( 3, -7 ) >>
        case_( ( is_non_negative, _1, _2 ) && ( is_odd, _1 ) ) >> to_return( false ) >>
        case_( ( is_odd, _1 ) ) >> to_return( true ) >>
        case_( ( is_non_negative, _1, _2 ) ) >> to_return( false ) >>    
        case_( _1 == -2 && _2 == 4 ) >> to_return( false ) >>
        in_place_return_;
        
    EXPECT_TRUE( result );
}

TEST(eswitch_v4_with_predicates, to_return_full_feature_3rd_match )
{
    using namespace eswitch_v4;
    

    auto is_odd = []( int i ){ return i % 2 != 0; };
    auto is_non_negative = []( int i, int j ){ return i >= 0 && j >= 0; };
  
    const auto result = eswitch( 4, 7 ) >>
        case_( ( is_non_negative, _1, _2 ) && ( is_odd, _1 ) ) >> to_return( false ) >>
        case_( ( is_odd, _1 ) ) >> to_return( false ) >>
        case_( ( is_non_negative, _1, _2 ) ) >> to_return( true ) >>    
        case_( _1 == -2 && _2 == 4 ) >> to_return( false ) >>
        in_place_return_;
        
    EXPECT_TRUE( result );
}

TEST(eswitch_v4_with_predicates, or_full_feature_1st_part_match )
{
    using namespace eswitch_v4;
    

    auto is_odd = []( int i ){ return i % 2 != 0; };

    auto is_non_negative = []( int i, int j ){ return i >= 0 && j >= 0; };
  
    const auto result = eswitch( 4, 7 ) >>
        case_( ( is_non_negative, _1, _2 ) || ( is_odd, _1 ) ) >> to_return( "yes" ) >>
        default_ >> to_return( "no" ) >>
        in_place_return_;
        
    EXPECT_TRUE( result == std::string( "yes" ) );
}

TEST(eswitch_v4_with_predicates, or_full_feature_2nd_part_match )
{
    using namespace eswitch_v4;
    

    auto is_odd = []( int i ){ return i % 2 != 0; };

    auto is_non_negative = []( int i, int j ){ return i >= 0 && j >= 0; };
  
    const auto result = eswitch( 3, -7 ) >>
        case_( ( is_non_negative, _1, _2 ) || ( is_odd, _1 ) ) >> to_return( "yes" ) >>
        default_ >> to_return( "no" ) >>
        in_place_return_;
        
    EXPECT_TRUE( result == std::string( "yes" ) );
}

auto is_odd( int i ){ return i % 2 != 0; }
auto is_non_negative( int i, int j ){ return i >= 0 && j >= 0; }

TEST(eswitch_v4_with_predicates, or_full_feature_1st_part_match_with_free_functions )
{
    using namespace eswitch_v4;
    
 
    const auto result = eswitch( 4, 7 ) >>
         case_( ( is_non_negative, _1, _2 ) || ( is_odd, _1 ) ) >> to_return( "yes" ) >>
         default_ >> to_return( "no" ) >>
         in_place_return_;
        
    EXPECT_TRUE( result == std::string( "yes" ) );
}

TEST(eswitch_v4_with_predicates, or_full_feature_2nd_part_match_with_free_functions )
{
    using namespace eswitch_v4;
    
 
    const auto result = eswitch( 3, -7 ) >>
         case_( ( is_non_negative, _1, _2 ) || ( is_odd, _1 ) ) >> to_return( "yes" ) >>
         default_ >> to_return( "no" ) >>
         in_place_return_;
        
    EXPECT_TRUE( result == std::string( "yes" ) );
}

TEST(eswitch_v4_with_predicates, or_full_feature_with_free_functions_and_fallthrough )
{
    using namespace eswitch_v4;
    
 
    const auto result = eswitch( 3, 7 ) >>
         case_( ( is_non_negative, _1, _2 ) || ( is_odd, _1 ) ) >> to_return( "yes" ) >> fallthrough_ >>
         default_ >> to_return( "no" ) >>
         in_place_return_;
        
    EXPECT_TRUE( result == std::string( "yes" ) );
}

TEST(eswitch_v4_with_predicates, or_full_feature_with_free_functions_and_fallthrough_and_return_in_lmbd )
{
    using namespace eswitch_v4;
    
 
    const auto result = eswitch( 3, 7 ) >>
         case_( ( is_non_negative, _1, _2 ) || ( is_odd, _1 ) ) >> []{ return "yes"; } >> fallthrough_ >>
         default_ >> []{ return "no"; } >>
         in_place_return_;
        
    EXPECT_TRUE( result == std::string( "yes" ) );
}

TEST(eswitch_v4_with_predicates, or_full_feature_with_free_functions_and_fallthrough_and_return_in_lmbd_default )
{
    using namespace eswitch_v4;
    
 
    const auto result = eswitch( 4, -7 ) >>
         case_( ( is_non_negative, _1, _2 ) || ( is_odd, _1 ) ) >> []{ return "yes"; } >> fallthrough_ >>
         default_ >> []{ return "no"; } >>
         in_place_return_;
        
    EXPECT_TRUE( result == std::string( "no" ) );
}

TEST(eswitch_v4_with_predicates, full_feature_with_free_functions_and_fallthrough )
{
    using namespace eswitch_v4;
    
 
    const auto result = eswitch( 3, -7 ) >>
        case_( ( is_non_negative, _1, _2 ) ) >> []{ return "no"; } >> fallthrough_ >>
        case_( ( is_odd, _1 ) ) >> []{ return "yes"; } >> fallthrough_ >>
        default_ >> []{ return "no"; } >>
        in_place_return_;
        
    EXPECT_TRUE( result == std::string( "yes" ) );
}

TEST(eswitch_v4_with_predicates, case_without_body )
{
    using namespace eswitch_v4;
    
 
     eswitch( 3, 7 ) >>
        case_( _1 == 3 ) >>
        case_( _2 == 7 ) >> []{ FAIL(); } >> fallthrough_ >>
        default_ >> []{ FAIL(); };

    eswitch( 3, 7 ) >>
        case_( ( is_non_negative, _1, _2 ) ) >>
        case_( ( is_odd, _1 ) ) >> []{ FAIL(); } >> fallthrough_ >>
        default_ >> []{ FAIL(); };        
}

TEST(eswitch_v4_with_predicates, 4_predicate_1st_match )
{
    using namespace eswitch_v4;
    
 
    auto is_nonzero = []( int i, int j, int k, int d ){ return i > 0 && j > 0 && k > 0 && d > 0; };

    const auto result = eswitch( 1, 7, 5, 10 ) >>
         case_( ( is_nonzero, _1, _2, _3, _4 ) && ( is_non_negative, _1, _2 ) && ( is_odd, _1 ) ) >> []{ return true; } >>
         case_( ( is_nonzero, _1, _2, _3, _4 ) || ( is_non_negative, _1, _2 ) || ( is_odd, _1 ) ) >> []{ FAIL(); } >>
         default_ >> []{ FAIL(); } >>
         in_place_return_;
        
    EXPECT_TRUE( result );
}

TEST(eswitch_v4_with_predicates, 4_predicate_2nd_match )
{
    using namespace eswitch_v4;
    
 
    auto is_nonzero = []( int i, int j, int k, int d ){ return i > 0 && j > 0 && k > 0 && d > 0; };

    const auto result = eswitch( 1, -7, 5, 10 ) >>
         case_( ( is_nonzero, _1, _2, _3, _4 ) && ( is_non_negative, _1, _2 ) && ( is_odd, _1 ) ) >> []{ FAIL(); } >>
         case_( ( is_nonzero, _1, _2, _3, _4 ) || ( is_non_negative, _4, _3 ) || ( is_odd, _1 ) ) >> []{ return true; } >>
         default_ >> []{ FAIL(); } >>
         in_place_return_;
        
    EXPECT_TRUE( result );
}

TEST(eswitch_v4_with_predicates, 4_predicate_default_match )
{
    using namespace eswitch_v4;
    
 
    auto is_nonzero = []( int i, int j, int k, int d ){ return i > 0 && j > 0 && k > 0 && d > 0; };

    const auto result = eswitch( 2, -7, 0, 10 ) >>
         case_( ( is_nonzero, _1, _2, _3, _4 ) && ( is_non_negative, _1, _2 ) && ( is_odd, _1 ) ) >> []{ FAIL(); } >>
         case_( ( is_nonzero, _1, _2, _3, _4 ) || ( is_non_negative, _2, _3 ) || ( is_odd, _1 ) ) >> []{ FAIL(); } >>
         default_ >> []{ return true; } >>
         in_place_return_;
        
    EXPECT_TRUE( result );
}

TEST(eswitch_v4_with_predicates, indexes_out_of_order_1st_match )
{
    using namespace eswitch_v4;
    
 
    auto is_nonzero = []( int i, int j, int k, int d ){ return i > 0 && j > 0 && k > 0 && d > 0; };

    const auto result = eswitch( 1, 7, 0, 10, 15 ) >>
         case_( ( is_nonzero, _5, _1, _4, _2 ) ) >> []{ return true; } >>
         case_( ( is_nonzero, _1, _2, _3, _4 ) || ( is_non_negative, _1, _2 ) || ( is_odd, _1 ) ) >> []{ FAIL(); } >>
         default_ >> []{ FAIL(); } >>
         in_place_return_;
        
    EXPECT_TRUE( result );
}

TEST(eswitch_v4_with_predicates, indexes_out_of_order_1st_match_less_args )
{
    using namespace eswitch_v4;
    
 
    auto is_nonzero = []( int i, int j ){ return i > 0 && j > 0; };

    const auto result = eswitch( 0, 7, 0, 10, 0 ) >>
         case_( ( is_nonzero, _4, _2 ) ) >> []{ return true; } >>
         default_ >> []{ FAIL(); } >>
         in_place_return_;
        
    EXPECT_TRUE( result );
}

TEST(eswitch_v4_with_predicates, indexes_out_of_order_1st_match_is_non_negative )
{
    using namespace eswitch_v4;
    

    const auto result = eswitch( 6, -7, -1, -10, 9 ) >>
         case_( ( is_non_negative, _5, _1 ) ) >> []{ return true; } >>
         default_ >> []{ FAIL(); } >>
         in_place_return_;
        
    EXPECT_TRUE( result );
}

TEST(eswitch_v4_with_predicates, indexes_out_of_order_1st_match_is_odd )
{
    using namespace eswitch_v4;
    
 
    const auto result = eswitch( 2, 4, 6, 1, 12 ) >>
         case_( ( is_odd, _4 ) ) >> []{ return true; } >>
         default_ >> []{ FAIL(); } >>
         in_place_return_;
        
    EXPECT_TRUE( result );
}

TEST(eswitch_v4_with_predicates, mixed_predicates_and_indexed_matching )
{
    using namespace eswitch_v4;
    
 
    const auto result = eswitch( 2, 4, 6, 1, 12 ) >>
         case_( ( is_odd, _4 ) && _1 == 2 && _2 == 4 ) >> []{ return true; } >>
         default_ >> []{ FAIL(); } >>
         in_place_return_;
        
    EXPECT_TRUE( result );
}

TEST(eswitch_v4_with_predicates, mixed_indexed_matching_and_predicates )
{
    using namespace eswitch_v4;
    
 
    const auto result = eswitch( 2, 4, 6, 1, 12 ) >>
         case_( _1 == 2 && _2 == 4 && ( is_odd, _4 ) ) >> []{ return true; } >>
         default_ >> []{ FAIL(); } >>
         in_place_return_;
        
    EXPECT_TRUE( result );
}

TEST(eswitch_v4_with_predicates, mixed_predicates_in_the_middle )
{
    using namespace eswitch_v4;
    
 
    const auto result = eswitch( 2, 4, 6, 1, 12 ) >>
         case_( _1 == 2 && ( is_odd, _4 ) && _2 == 4 ) >> []{ return true; } >>
         default_ >> []{ FAIL(); } >>
         in_place_return_;
        
    EXPECT_TRUE( result );
}

TEST(eswitch_v4_with_predicates, mixed_predicates_and_index_matching_empty_body )
{
    using namespace eswitch_v4;
    
    eswitch( 2, 4, 6, 1, 12 ) >>
         case_( _1 == 2 && ( is_odd, _4 ) && _2 == 4 ) >>
         case_( _1 == 2 ) >> []{ FAIL(); };
}

TEST(eswitch_v4_with_predicates, mixed_predicates_and_index_matching_in_separate_cases )
{
    using namespace eswitch_v4;
    
 
    const bool result = eswitch( 2, 4, 6, 1, 12 ) >>
        case_( _1 == 2 && ( is_odd, _4 ) && _2 == 4 ) >> to_return( true ) >>
        case_( _1 == 2 )  >> to_return( false ) >>
        case_( ( is_odd, _4 ) ) >> to_return( false ) >>
        case_( _5 == 12 ) >> to_return( false ) >>
        in_place_return_;

    EXPECT_TRUE( result );
}

TEST(eswitch_v4_with_predicates, mixed_predicates_and_index_matching_in_separate_cases_FALLTHROUGH_till_2nd )
{
    using namespace eswitch_v4;
    
 
    const int result = eswitch( 2, 4, 6, 1, 12 ) >>
        case_( _1 == 2 && ( is_odd, _4 ) && _2 == 4 ) >> []{} >> fallthrough_ >>
        case_( _1 == 2 )  >> to_return( 2 ) >>
        case_( ( is_odd, _4 ) ) >> to_return( 3 ) >> 
        case_( _5 == 12 ) >> to_return( 4 ) >>
        in_place_return_;

    EXPECT_TRUE( result == 2 );
}

TEST(eswitch_v4_with_predicates, mixed_predicates_and_index_matching_in_separate_cases_FALLTHROUGH_till_3rd )
{
    using namespace eswitch_v4;
    
 
    const int result = eswitch( 2, 4, 6, 1, 12 ) >>
        case_( _1 == 2 && ( is_odd, _4 ) && _2 == 4 ) >> []{} >> fallthrough_ >>
        case_( _1 == 2 )  >> []{} >> fallthrough_ >>
        case_( ( is_odd, _4 ) ) >> to_return( 3 ) >> 
        case_( _5 == 12 ) >> to_return( 4 ) >>
        in_place_return_;

    EXPECT_TRUE( result == 3 );
}

TEST(eswitch_v4_with_predicates, mixed_predicates_and_index_matching_in_separate_cases_FALLTHROUGH_till_4th )
{
    using namespace eswitch_v4;
    
 
    const int result = eswitch( 2, 4, 6, 1, 12 ) >>
        case_( _1 == 2 && ( is_odd, _4 ) && _2 == 4 ) >> []{} >> fallthrough_ >>
        case_( _1 == 2 )  >> []{} >> fallthrough_ >>
        case_( ( is_odd, _4 ) ) >> []{} >> fallthrough_ >>
        case_( _5 == 12 ) >> to_return( 4 ) >>
        in_place_return_;

    EXPECT_TRUE( result == 4 );
}

TEST(eswitch_v4_with_predicates, mixed_predicates_and_index_matching_in_separate_cases_FALLTHROUGH_till_default )
{
    using namespace eswitch_v4;
    
   
    const int result = eswitch( 2, 4, 6, 1, 12 ) >>
        case_( _1 == 2 && ( is_odd, _4 ) && _2 == 4 ) >> []{} >> fallthrough_ >>
        case_( _1 == 2 )  >> []{} >> fallthrough_ >>
        case_( ( is_odd, _4 ) ) >> []{} >> fallthrough_ >>
        case_( _5 == 12 ) >> []{} >> fallthrough_ >>
        default_ >> to_return( 5 ) >>
        in_place_return_;

    EXPECT_TRUE( result == 5 );
}

TEST(eswitch_v4_with_predicates, mixed_2_predicates_and_index_matching )
{
    using namespace eswitch_v4;
    

    auto is_nonzero = []( int i ) { return i > 0; };

    {
        const int result = eswitch( 2, 4, 6, 1, 12 ) >>
            case_( _1 == 2 && ( is_odd, _4 ) && ( is_nonzero, _2 ) && _2 == 4 ) >> []{ return 10; } >> fallthrough_ >>
            case_( _1 == 2 )  >> []{} >> fallthrough_ >>
            case_( ( is_odd, _4 ) ) >> []{} >> fallthrough_ >>
            case_( _5 == 12 ) >> []{} >> fallthrough_ >>
            default_ >> to_return( 5 ) >>
            in_place_return_;

        EXPECT_TRUE( result == 10 );
    }
    {
        const int result = eswitch( 2, 4, 6, 1, 12 ) >>
            case_( ( is_odd, _4 ) && _1 == 2 && ( is_nonzero, _2 ) && _2 == 4 ) >> []{ return 11; } >> fallthrough_ >>
            case_( _1 == 2 )  >> []{} >> fallthrough_ >>
            case_( ( is_odd, _4 ) ) >> []{} >> fallthrough_ >>
            case_( _5 == 12 ) >> []{} >> fallthrough_ >>
            default_ >> to_return( 5 ) >>
            in_place_return_;

        EXPECT_TRUE( result == 11 );
    }
    {
        const int result = eswitch( 2, 4, 6, 1, 12 ) >>
            case_( ( is_odd, _4 ) && ( is_nonzero, _2 ) && _1 == 2 && _2 == 4 ) >> []{ return 12; } >> fallthrough_ >>
            case_( _1 == 2 )  >> []{} >> fallthrough_ >>
            case_( ( is_odd, _4 ) ) >> []{} >> fallthrough_ >>
            case_( _5 == 12 ) >> []{} >> fallthrough_ >>
            default_ >> to_return( 5 ) >>
            in_place_return_;

        EXPECT_TRUE( result == 12 );
    }

    {
        const int result = eswitch( 2, 4, 6, 1, 12 ) >>
            case_( ( is_odd, _4 ) && ( is_nonzero, _2 ) && _2 == 4 && _1 == 2 ) >> []{ return 13; } >> fallthrough_ >>
            case_( _1 == 2 )  >> []{} >> fallthrough_ >>
            case_( ( is_odd, _4 ) ) >> []{} >> fallthrough_ >>
            case_( _5 == 12 ) >> []{} >> fallthrough_ >>
            default_ >> to_return( 5 ) >>
            in_place_return_;

        EXPECT_TRUE( result == 13 );
    }

    {
        const int result = eswitch( 2, 4, 6, 1, 12 ) >>
            case_( _2 == 4 && _1 == 2 && ( is_odd, _4 ) && ( is_nonzero, _2 ) ) >> []{ return 14; } >> fallthrough_ >>
            case_( _1 == 2 )  >> []{} >> fallthrough_ >>
            case_( ( is_odd, _4 ) ) >> []{} >> fallthrough_ >>
            case_( _5 == 12 ) >> []{} >> fallthrough_ >>
            default_ >> to_return( 5 ) >>
            in_place_return_;

        EXPECT_TRUE( result == 14 );
    }

    
    {
        const int result = eswitch( 2, 4, 6, 1, 12 ) >>
            case_( _2 == 4 && ( is_odd, _4 ) && _1 == 2 && ( is_nonzero, _2 ) ) >> []{ return 15; } >> fallthrough_ >>
            case_( _1 == 2 )  >> []{} >> fallthrough_ >>
            case_( ( is_odd, _4 ) ) >> []{} >> fallthrough_ >>
            case_( _5 == 12 ) >> []{} >> fallthrough_ >>
            default_ >> to_return( 5 ) >>
            in_place_return_;

        EXPECT_TRUE( result == 15 );
    }    
}

TEST(eswitch_v4_operator_comma, should_compile )
{
    using namespace eswitch_v4;
    

    {
    auto rslt = ( is_odd, std::string{"Hello"} );
    EXPECT_TRUE( rslt == std::string{"Hello"} );
    }

    {
    auto rslt = ( is_odd, int(1) );
    EXPECT_TRUE( rslt == 1 );
    }

    {
    auto rslt = ( is_odd, fallthrough_ );
    EXPECT_TRUE( ( std::is_same< decltype( rslt ), std::remove_const_t< decltype( fallthrough_ ) > >::value ) );
    }
}

#include <regex>

struct RegexMatcher
{
    std::regex rgx_;

    RegexMatcher( const std::regex & rgx ) : rgx_( rgx ){}

    friend bool operator==( const std::string & v, const RegexMatcher & rm )
    {
        return std::regex_match( v, rm.rgx_ );
    }

    friend bool operator!=( const std::string & v, const RegexMatcher & rm )
    {
        return !( v == rm );
    }
};

CASE_OVERLOAD( std::regex, RegexMatcher );

std::regex operator "" _r( const char* rgx, size_t ){
  return std::regex( rgx );
}

TEST(eswitch_v4_custom_extention, regex )
{
     using namespace eswitch_v4;

    const auto phone_number( "^[+]*[(]{0,1}[0-9]{1,4}[)]{0,1}[-\\s\\./0-9]*$"_r );
    const auto email( "[\\w-]+@([\\w-]+\\.)+[\\w-]+"_r );

    {
        bool executed = false;

        std::string text{ "joe@aol.com" };

        eswitch( text ) >> 
            case_( _1 == phone_number ) >> []{ FAIL(); } >>
            case_( _1 == email )        >> [&]{ executed = true; };

        EXPECT_TRUE( executed );
    }

    {
        auto phone_number( "^[+]*[(]{0,1}[0-9]{1,4}[)]{0,1}[-\\s\\./0-9]*$"_r );
        auto email( "[\\w-]+@([\\w-]+\\.)+[\\w-]+"_r );

        bool executed = false;

        std::string text{ "joe@aol.com" };

        eswitch( text ) >> 
            case_( _1 == phone_number ) >> []{ FAIL(); } >>
            case_( _1 == email )        >> [&]{ executed = true; };

        EXPECT_TRUE( executed );
    }

    {
        auto phone_number( "^[+]*[(]{0,1}[0-9]{1,4}[)]{0,1}[-\\s\\./0-9]*$"_r );
        auto email( "[\\w-]+@([\\w-]+\\.)+[\\w-]+"_r );

        bool executed = false;

        std::string text{ "joe@aol.com" };

        eswitch( text ) >> 
            case_( phone_number ) >> []{ FAIL(); } >>
            case_( email )        >> [&]{ executed = true; };

        EXPECT_TRUE( executed );
    }

    {
        bool executed = false;

        std::string text{ "joe@aol.com" };

        eswitch( text ) >> 
            case_( _1 == "^[+]*[(]{0,1}[0-9]{1,4}[)]{0,1}[-\\s\\./0-9]*$"_r ) >> []{ FAIL(); } >>
            case_( _1 == "[\\w-]+@([\\w-]+\\.)+[\\w-]+"_r )        >> [&]{ executed = true; };

        EXPECT_TRUE( executed );
    }

    {
        bool executed = false;

        std::string text{ "joe@aol.com" };

        eswitch( text ) >> 
            case_( "^[+]*[(]{0,1}[0-9]{1,4}[)]{0,1}[-\\s\\./0-9]*$"_r ) >> []{ FAIL(); } >>
            case_( "[\\w-]+@([\\w-]+\\.)+[\\w-]+"_r )        >> [&]{ executed = true; };

        EXPECT_TRUE( executed );
    }

    {
        bool executed = false;

        std::string text{ "joe@aol.com" };

        eswitch( text ) >> 
            case_( phone_number ) >> []{ FAIL(); } >>
            case_( email )        >> [&]{ executed = true; };

        EXPECT_TRUE( executed );
    }

    {
        bool executed = false;

        std::string text{ "+(123)-456-78-90" };

        eswitch( text ) >> 
            case_( _1 == phone_number ) >> [&]{ executed = true; } >>
            case_( _1 == email )        >> [&]{ FAIL(); };

        EXPECT_TRUE( executed );
    }

    {
        bool executed = false;

        std::string text{ "+(123)-456-78-90" };

        eswitch( text ) >> 
            case_( phone_number ) >> [&]{ executed = true; } >>
            case_( email )        >> [&]{ FAIL(); };

        EXPECT_TRUE( executed );
    }
}

TEST(eswitch_v4_bug, 1st_match_executed_next_case_after_return )
{
    using namespace eswitch_v4;

    auto actual = eswitch( 1 ) >>
        case_( 1 ) >> to_return( true ) >>
        case_( 2 ) >> []{ throw( "FAILED" ); return false; } >>
        case_( 3 ) >> []{ throw( "FAILED" ); return false; } >>
        default_ >> []{ throw( "FAILED" ); return false; } >>
        in_place_return_;

    EXPECT_TRUE( actual );
}
    

TEST(eswitch_v4_bug, 2nd_match_executed_next_case_after_return )
{
    using namespace eswitch_v4;

    auto actual = eswitch( 2 ) >>
        case_( 1 ) >> []{ throw( "FAILED" ); return false; } >>
        case_( 2 ) >> to_return( true ) >>
        case_( 3 ) >> []{ throw( "FAILED" ); return false; } >>
        default_ >> []{ throw( "FAILED" ); return false; } >>
        in_place_return_;

    EXPECT_TRUE( actual );
}


TEST(eswitch_v4_bug, 3rd_match_executed_next_case_after_return )
{
    using namespace eswitch_v4;

    auto actual = eswitch( 3 ) >>
        case_( 1 ) >> []{ throw( "FAILED" ); return false; } >>
        case_( 2 ) >> []{ throw( "FAILED" ); return false; } >>
        case_( 3 ) >> to_return( true ) >>
        default_ >> []{ throw( "FAILED" ); return false; } >>
        in_place_return_;

    EXPECT_TRUE( actual );
}

TEST(eswitch_v4_bug, 4th_match_executed_next_case_after_return )
{
    using namespace eswitch_v4;

    auto actual = eswitch( 4 ) >>
        case_( 1 ) >> []{ throw( "FAILED" ); return false; } >>
        case_( 2 ) >> []{ throw( "FAILED" ); return false; } >>
        case_( 3 ) >> []{ throw( "FAILED" ); return false; } >>
        default_ >> to_return( true ) >>
        in_place_return_;

    EXPECT_TRUE( actual );
}

TEST(eswitch_v4_bug, fallthrough_match_executed_next_case )
{
    using namespace eswitch_v4;

    auto actual = eswitch( 1 ) >>
        case_( 1 ) >> []{} >> fallthrough_ >>
        case_( 2 ) >> []{ return true; } >>
        case_( 3 ) >> []{ throw( "FAILED" ); return false; } >>
        default_ >> []{ throw( "FAILED" ); return false; } >>
        in_place_return_;

    EXPECT_TRUE( actual );
}

TEST(eswitch_v4_, in_range_1_10 )
{
    using namespace eswitch_v4;

    int someVal = 9;

    bool executed = false;

    eswitch( someVal ) >>
        case_( ( in_range< 11, 15 >, _1 ) ) >> []{ FAIL(); } >>
        case_( ( in_range< 1, 10 >, _1 ) )  >> [&]{ executed = true; } >>
        default_ >> []{ FAIL(); };

    EXPECT_TRUE( executed );
}

TEST(eswitch_v4_, in_range_2_4 )
{
    using namespace eswitch_v4;

    int someVal = 3;

    bool executed = false;

    eswitch( someVal ) >>
        case_( ( in_range< 2, 4 >, _1 ) ) >> [&]{ executed = true; } >>
        case_( ( in_range< 1, 10 >, _1 ) ) >> [&]{ FAIL(); } >>
        default_ >> []{ FAIL(); };

    EXPECT_TRUE( executed );
}

TEST(eswitch_v4_case, in_1_10 )
{
    using namespace eswitch_v4;

    int someVal = 9;

    bool executed = false;

    eswitch( someVal ) >>
        case_( _1.in( 11, 15 ) ) >> []{ FAIL(); } >>
        case_( _1.in( 1, 10 ) )  >> [&]{ executed = true; } >>
        default_ >> []{ FAIL(); };

    EXPECT_TRUE( executed );
}


TEST(eswitch_v4_case, in_a_z )
{
    using namespace eswitch_v4;

    char someVal = 'v';

    bool executed = false;

    eswitch( someVal ) >>
        case_( _1.in( 'A', 'Z' ) ) >> [&]{ FAIL(); } >>
        case_( _1.in( 'a', 'z' ) ) >> [&]{ executed = true; } >>
        default_ >> []{ FAIL(); };

    EXPECT_TRUE( executed );
}

TEST(eswitch_v4_case, in_A_Z )
{
    using namespace eswitch_v4;

    char someVal = 'T';

    bool executed = false;

    eswitch( someVal ) >>
        case_( _1.in( 'A', 'Z' ) ) >> [&]{ executed = true; } >>
        case_( _1.in( 'a', 'z' ) ) >> [&]{ FAIL(); } >>
        default_ >> []{ FAIL(); };

    EXPECT_TRUE( executed );
}

TEST(eswitch_v4_case, in_for_each_a_z_and_A_Z )
{
    using namespace eswitch_v4;

    for( char ch = 'a'; ch <= 'Z'; ++ch )
    {
        bool executed = false;

        eswitch( ch ) >>
            case_( _1.in( 'a', 'z' ) || _1.in( 'A', 'Z' ) ) >> [&]{ executed = true; } >>
            default_ >> []{ FAIL(); };

        EXPECT_TRUE( executed );
    }
}

TEST(eswitch_v4_case, in_1_10_lvalue )
{
    using namespace eswitch_v4;

    int someVal = 9;

    bool executed = false;

    int i = 1;
    int j = 10;
    eswitch( someVal ) >>
        case_( _1.in( 11, 15 ) ) >> []{ FAIL(); } >>
        case_( _1.in( i, j ) )  >> [&]{ executed = true; } >>
        default_ >> []{ FAIL(); };

    EXPECT_TRUE( executed );
}

TEST(eswitch_v4_case, in_1_200_several_values_via_and )
{
    using namespace eswitch_v4;

    int Val1 = 9;
    int Val2 = 110;

    bool executed = false;

    eswitch( Val1, Val2 ) >>
        case_( _1.in( 1, 10 ) && _2.in( 100, 110 ) ) >> [&]{ executed = true; } >>
        default_ >> []{ FAIL(); };

    EXPECT_TRUE( executed );
}

TEST(eswitch_v4_case, in_1_200_several_values_via_or_1st_match )
{
    using namespace eswitch_v4;

    int Val1 = 9;
    int Val2 = 110;

    bool executed = false;

    eswitch( Val1, Val2 ) >>
        case_( _1.in( 1, 10 ) || _2.in( 111, 112 ) ) >> [&]{ executed = true; } >>
        default_ >> []{ FAIL(); };

    EXPECT_TRUE( executed );
}

TEST(eswitch_v4_case, in_1_200_several_values_via_or_2nd_match )
{
    using namespace eswitch_v4;

    int Val1 = 9;
    int Val2 = 110;

    bool executed = false;

    eswitch( Val1, Val2 ) >>
        case_( _1.in( 11, 12 ) || _2.in( 1, 110 ) ) >> [&]{ executed = true; } >>
        default_ >> []{ FAIL(); };

    EXPECT_TRUE( executed );
}

/*
        std::tuple< int, double, std::string > tup;

        eswitch( tup ) >>
            case_( _1 == 10 and _2 == 5.5 and _3 == "HTTP" ) >> []{};

        std::string text = "field_name=value";
        auto res = tokenize( text, '=' );

        eswitch( res[0], res[0] ) >>
            case_( _1 == "addressSearch" ) >>
            case_( _1 == "addressSearch" and _2 == "REQUESTED" ) >> []{};

        double d = 2.0002;

        
        eswitch( d ) >>
            case_( 2.001 ) >>
            case_( 2.0002 ) >> []{};

        
        eswitch( text ) >>
            case_( std::regex("[a-z]+\\.txt") ) >> result_of( []( const auto & result ){ ... } );

        
        eswitch( val ) >>
            case_( ( predicate_is_odd, _1, _2 ) and ( predicate_is_non_negative, _1 ) >>
            case_( ( predicate_id_prime, _1 ) ) >>;


        std::for_each( vec, 
            eswitch( amount_args< 2 > ) >>
                case_( _1 == 5 ) >> first_match_handler
                case_( _1 == 6 ) >> second_match_handler );

        std::for_each( vec, 
            eswitch( placeholder, placeholder ) >>
                case_( _1 == 5 ) >> first_match_handler
                case_( _1 == 6 ) >> second_match_handler );

                
        std::find_if( vec, 
            eswitch( placeholder ) >>
                case_( _1 == 5 ) >> to_return( true ) >>
                default_ >> to_return( false ) );


        std::find_if( vec, []( const int value ){ return value == 5 ? true : false; } );
        
        std::find_if( vec, case_( arg1 == 5 ) >> to_return( true ) );

        case( _1 in_ {1, 2} )

*/