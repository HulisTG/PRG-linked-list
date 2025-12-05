#include "../lib/unity.h"
#include "../linked_list.h"


node *test_head = NULL;

int a;

void setUp(void) {
    
    test_head = NULL;
    
    printf("Setup: Hodnota nastavena na NULL. \r\n");
}

void tearDown(void) {
    

    linked_list_destroy(&test_head);

    printf("TEARDOWN: Konec testu. \r\n");
}

void test_function_destroy(void) {

    TEST_ASSERT_NULL_MESSAGE(test_head, "Hlava by měla být NULL");

    bool success = linked_list_add(&test_head, 1);

    TEST_ASSERT_TRUE_MESSAGE(success, "Vlozeni selhalo");

    TEST_ASSERT_NOT_NULL_MESSAGE(test_head, "Hlava by nemela  byt NULL");

    linked_list_destroy(&test_head);

    TEST_ASSERT_NULL_MESSAGE(test_head, "Hlava by měla být NULL");

}

void test_function_add(void) {
    
    TEST_ASSERT_NULL_MESSAGE(test_head, "Hlava by měla být NULL");

    bool success = linked_list_add(&test_head, 6);

    TEST_ASSERT_TRUE_MESSAGE(success, "Vlozeni selhalo");

    TEST_ASSERT_NOT_NULL_MESSAGE(test_head, "Hlava by nemela  byt NULL");

    TEST_ASSERT_EQUAL_INT(6, test_head->data);

    success = linked_list_add(&test_head, 9);

    TEST_ASSERT_TRUE_MESSAGE(success, "Vlozeni selhalo");

    TEST_ASSERT_EQUAL_INT(9, test_head->data);
    
    TEST_ASSERT_EQUAL_INT(6, test_head->next->data);

    
}

void test_function_remove(void){
    bool success;
    
    success = linked_list_add(&test_head, 3);
    TEST_ASSERT_TRUE(success);
    TEST_ASSERT_NOT_NULL(test_head);
    TEST_ASSERT_EQUAL_INT(3, test_head->data);

    success = linked_list_remove(&test_head);
    TEST_ASSERT_TRUE(success);
    TEST_ASSERT_NULL(test_head);

    success = linked_list_add(&test_head, 8);
    TEST_ASSERT_TRUE(success);

    success = linked_list_add(&test_head, 11);
    TEST_ASSERT_TRUE(success);

    success = linked_list_remove(&test_head);
    TEST_ASSERT_TRUE(success);
    TEST_ASSERT_NOT_NULL(test_head);
    TEST_ASSERT_EQUAL_INT(8, test_head->data);

}


void test_function_size(void){

    size_t size = linked_list_size(test_head);
    TEST_ASSERT_EQUAL_size_t(0, size);

    bool success = linked_list_add(&test_head, 7); 
    TEST_ASSERT_TRUE(success);

    size = linked_list_size(test_head);
    TEST_ASSERT_EQUAL_size_t(1, size);



}

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_function_destroy);
    RUN_TEST(test_function_add);
    RUN_TEST(test_function_remove);
    RUN_TEST(test_function_size);
    return UNITY_END();
}