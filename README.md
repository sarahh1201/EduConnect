# EduConnect

- [v0](/v0) - This version of EduConnect includes all the header files and algorithms that have been built separately.
- [v1](/v1) - This version of EduConnect is bringing all the components together to make the platform cohesive. 
    - Backend (header files)
        - [AcceptRequest.h](v1/backend/AcceptRequesth) - The logic of a tutor accepting a request. 
        - [Authorization.h](v1/backend/Authorization.h) - All the login logic, contains password recovery and changing. 
        - [ClearScreen.h](v1/backend/ClearScreen.h) - This will just clear the contents in the terminal, making it easier to see. There are two versions of the function. One will verify with the user if they would like to clear the screen, and the other will clear with no warning. 
        - [CreateAccount.h](v1/backend/CreateAccount.h) - New users can create a tutor or student account. 
        - [Dashboards.h](v1/backend/Dashboards.h) - The menus for students or tutors. 
        - [Decode.h](v1/backend/Decode.h) - This file will take the contents from the .csv files. In terms of scalability, this is not the best method, so for future improvements, implementing the platform with SQL would be ideal. 
        - [MakeRequest.h](v1/backend/MakeRequest.h) - As a student, you can submit a new request. 
        - [RequestProcess.h](v1/backend/RequestProcess.h) - This is the logic of the matching algorithm. This is more on the backend side. 
        - [TutorSearch.h](v1/backend/TutorSearch.h) - This contains the various methods a student can search for a tutor and then contact them via email. 
    - Data (csv files) - All the .csv files where information is being stored and retrieved. Since this is a school project and our datasets are quite small, this is feasible; however, if we wanted to scale this project, we would have to rework this project with a database. 
- [v_ui](/v_ui) - This is the version of EduConnect that has a UI. While converting from v1 to v_ui there were some issues that we ran into. The main issue is that QT does not like everything to be in header files; that is only one of the problems. Most of the code in this implementation is not the same because QT does not use cout to print since we are not printing to a terminal. There are a lot more steps to print out to different ui components. Last thing to mention is that not all of the features of EduConnect have been implemented in this version, as it was time-consuming to go through and rewrite some of the code as well as make the ui for it. In the future, we would love to improve the ui design and make it more functional. 
