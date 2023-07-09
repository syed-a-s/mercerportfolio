with Ada.Text_IO;            use Ada.Text_IO;
with Ada.Strings.Fixed;      use Ada.Strings.Fixed;
with Ada.Integer_Text_IO;    use Ada.Integer_Text_IO;
with Ada.IO_Exceptions;      use Ada.IO_Exceptions;

procedure screenformat is

      file : file_type;
      userFile : string(1..100); len : integer;
      value : character;
      string_array : array (1..5000000) of character;
      pos : integer;
      counter : integer;

begin
   -- ask user for file name
      put("What file would you like to format? --> ");  
      get_line(userFile, len);
    
   -- storing message from input file into character array      
      open (file => file,
            mode => in_file,  
            name => userFile(1..len));
            
      pos := 0;
      while not Ada.Text_IO.End_Of_File(File) loop
            get(file => file, item => value);
            pos := pos + 1;
            string_array(pos) := value;
      end loop;  
      
   -- remove any unnecessary blank spaces
      counter := 1;
      for i in 1..pos loop
            if string_array(i+1) /= ' ' then
                  counter := counter + 1;
                  string_array(counter) := string_array(i);
            end if;
      end loop;
   
      put(string_array(1));
      put(string_array(2));
      put(string_array(3));
      put(string_array(4));
      put(string_array(5));
      put(string_array(6));
      put(string_array(7));
      put(string_array(8));
      put(string_array(9));
      put(string_array(10));
      put(string_array(11));
      close(file);
      
end screenformat;