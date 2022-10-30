# Contributing to pptest

First, thank you and welcome.

## Why contribute?

- To improve code.
- To add more features and implementations.
- To fix bugs and typos.
- To write or fix documentation.

## How to contribute?

- Create a personal fork of the project on Github.
- Then create a new branch to work on from dev.
- Clone the fork on your local machine. Your remote repo on Github is called `origin`.
- Add the original repository as a remote called `upstream`.
- Create a **new branch** to work on. Branch from `dev` or from `master`.
- Implement/fix your feature, comment your code.
- Follow the code style of the project, including indentation.
- Add or change the documentation as needed.
- Squash your commits into a single commit with git's [interactive rebase](https://docs.github.com/en/get-started/using-git/about-git-rebase). Create a new branch if necessary.
- Push your branch to your fork on Github, the remote `origin`.
- Once the pull request is approved and merged you can pull the changes from `upstream` to your local repo and delete your extra branch(es).

## Notes

- Commit message header should be in present tense and it should describe what was changed or added. You can use which ever tense you like in the message body. Follow this example:

```md
Add: colored_console_reporter, colored_console_reporter_tests

  - Added a new reporter to print with color to the console.
  - Wrote tests for the reporter.
  - Windows implementation only.
```

- Use of STL is **not allowed** in the testing layer. However, it is allowed if it is used in reporter implementations.
- You can implement different types of reporters.
- Remember to create snake-case aliases.
- \[will add more notes...\]
