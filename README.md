 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\<"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
# TODO Planner
 > Your author list below should include links to all members GitHub and should begin with a "\<" (remove existing author).
 
 > Authors: \<[Abdullah Chaudhry](https://github.com/ChauAbdul786)\>, \<[Andrew Shim](https://github.com/ashim020)\>, \<[Alexander Roh](https://github.com/Colliquake)\>
 
 > You will be forming a group of **THREE** students and work on an interesting project that you will propose yourself (in this `README.md` document). You can pick any project that you'd like, but it needs ot implement three design patterns. Each of the members in a group is expected to work on at least one design pattern and its test cases. You can, of course, help each other, but it needs to be clear who will be responsible for which pattern and for which general project features.
 
 > ## Expectations
 > * Incorporate **three** distinct design patterns, *two* of the design patterns need to be taught in this course:
 >   * Composite, Strategy, Abstract Factory, Visitor
 > * All three design patterns need to be linked together (it can't be three distinct projects)
 > * Your project should be implemented in C/C++. If you wish to choose anoher programming language (e.g. Java, Python), please discuss with your lab TA to obtain permission.
 > * You can incorporate additional technologies/tools but they must be approved (in writing) by the instructor or the TA.
 > * Each member of the group **must** be committing code regularly and make sure their code is correctly attributed to them. We will be checking attributions to determine if there was equal contribution to the project.

## Project Description
 > Your project description should summarize the project you are proposing. Be sure to include
 > * Why is it important or interesting to you?
 >   * It is important as students to organize tasks and events to better manage our schedules. Without an appropriate method of doing so, it would be easy to feel overwhelmed and confused. An online TODO planner would be a paperless solution to visualize such responsibilities according to days, weeks, and months. 
 > * What languages/tools/technologies do you plan to use? (This list may change over the course of the project)
 >   * C++ - Main Language we will be using
 >   * HTML/CSS - If time permits and we decide to pursue making this a web application
 > * What will be the input/output of your project?
 >   * Input would consist of different types of tasks/events that a user would want to organize/manage, and output would consist of a kind of calendar/planner that helps them visualize their tasks/events, their respectives times, and how these different times line up with each other.
 > * What are the three design patterns you will be using. For each design pattern you must:
 >   * Explain in 3 - 5 sentences why you picked this pattern and what feature you will implement with it
 >      * Strategy
 >         * The strategy pattern is effective when many different classes don’t vary much in composition, but rather in behavior. This makes it effective for a TODO planner such as ours because we can treat tasks as objects to implement this pattern. Each task will be mostly similar in composition, with only slight behavioral differences. For example, a task that is to be an all day task (such as a holiday event) will have a different relationship to the calendar than an event that occupies a specific time (such as a scheduled test).
 >      * Composite
 >         * The composite design pattern allows objects to be composed into tree structures, representing part-whole hierarchies. This makes it effective for a TODO planner such as ours because we can categorize components of the year into tree structures in which days are under weeks, which are under months and so forth. Also, it would allow the user to treat the composition of individual objects uniformly. For example, tasks within a day could be treated the same as tasks within a week or a month. 
 >      * Decorator
 >         * The decorator design pattern allows objects to gain new functionalities without altering their structures.This makes it effective for a TODO planner such as ours because we can treat each task (that the user inputs) as an object and “decorate” it (categorize it) with different groups. In doing so, we avoid disrupting any structures or patterns, and are able to simply give each “task” an additional function(s). Some categories, such as homework, could be given a higher priority than other categories. All the user needs to worry about is giving their task a title, and categorizing it based on what their task is.

 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to 
 > * Set up your GitHub project board as a Kanban board for the project. It should have columns that map roughly to 
 >   * Backlog, TODO, In progress, In testing, Done
 >   * You can change these or add more if you'd like, but we should be able to identify at least these.
 > * There is no requirement for automation in the project board but feel free to explore those options.
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller development tasks as issues and assign them to team members. Place these in the `Backlog` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
## Class Diagram
 > Include a class diagram(s) for each design pattern and a description of the diagram(s). This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper OMT notation (as discussed in the course slides). You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description). 
 
 <img src=images/project diagram.png">
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
