# EduConnect

- [v0](/v0) - This version of EduConnect are all the header files and algorithms that have been built seperately.
- [v1](/v1) - This version of EduConnect is bringing all the components together to make the platform cohesive. 

- Backend (header files)
    - [AcceptRequest.h](v1/backend/AcceptRequesth) - The logic of a tutor accepting a request. 
    - [Authorization.h](v1/backend/Authorization.h) - All the login logic, contains password recovery and changing. 
    - [ClearScreen.h](v1/backend/ClearScreen.h) - This will jsut clear the contents in the terminal making it easier to see. There are two versions of the function. One will verify with the user if they would like to clear the screen and the other will clear with no warning. 
    - [CreateAccount.h](v1/backend/CreateAccount.h) - New users can create a tutor or student account. 
    - [Dashboards.h](v1/backend/Dashboards.h) - The menus for students or tutors. 
    - [Decode.h](v1/backend/Decode.h) - This file will take the contents from the .csv files. In terms of scalability this is not the best method so for future improvements implementing the platform with sql would be ideal. 
    - [MakeRequest.h](v1/backend/MakeRequest.h) - As a student you can submit a new request. 
    - [RequestProcess.h](v1/backend/RequestProcess.h) - This is the logic of the matching algorithm. This is more on the backend side. 
    - [TutorSearch.h](v1/backend/TutorSearch.h) - This contains the various methods a student can search for a tutor and then contact them via email. 
