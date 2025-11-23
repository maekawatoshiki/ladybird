#include <AK/Format.h>
#include <AK/StringView.h>
#include <LibJS/Bytecode/Interpreter.h>
#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Script.h>

int main()
{
    auto vm = JS::VM::create();
    auto context = JS::create_simple_execution_context<JS::GlobalObject>(*vm);
    auto& realm = *context->realm;

    AK::StringView source { "1 + ", 4 };
    auto script = JS::Script::parse(source, realm);
    if (script.is_error()) {
        for (auto const& error : script.error())
            dbgln("error = {}", error.to_string());
        return 1;
    }

    auto result = vm->bytecode_interpreter().run(script.value());
    if (result.is_throw_completion())
        return 1;

    dbgln("result = {}", result.value().as_double());

    return 0;
}
