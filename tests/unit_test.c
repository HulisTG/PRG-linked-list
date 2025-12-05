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

// not needed when using generate_test_runner.rb
int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_function_destroy);
    RUN_TEST(test_function_add);
    return UNITY_END();
}