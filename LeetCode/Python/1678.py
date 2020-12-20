def peek(command, index, char):
    if index >= len(command):
        return False
    return command[index] == char
    
class Solution:    
    def interpret(self, command: str) -> str:
        output=""
        i = 0
        while i < len(command):
            if command[i] == 'G':
                output += 'G'
                i += 1
            elif command[i] == '(' and peek(command,i+1,'a'):
                output += 'al'
                i += 3
            elif command[i] == '(' and peek(command,i+1,')'):
                output += 'o'
                i += 2
            else:
            	i += 1
        return output
        

sol = Solution()
print(sol.interpret("G()(al)"))