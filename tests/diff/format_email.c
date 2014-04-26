static void assert_email_match(
	const char *expected,
	const char *oidstr,
	git_diff_format_email_options *opts)
	git_oid_fromstr(&oid, oidstr);

	cl_git_pass(git_commit_lookup(&commit, repo, &oid));

	opts->id = git_commit_id(commit);
	opts->author = git_commit_author(commit);
	if (!opts->summary)
		opts->summary = git_commit_summary(commit);

	cl_git_pass(git_diff__commit(&diff, repo, commit, NULL));
	cl_git_pass(git_diff_format_email(&buf, diff, opts));

	cl_assert_equal_s(expected, git_buf_cstr(&buf));
	git_buf_clear(&buf);

	cl_git_pass(git_diff_commit_as_email(
		&buf, repo, commit, 1, 1, opts->flags, NULL));
	cl_assert_equal_s(expected, git_buf_cstr(&buf));

	git_diff_free(diff);
	git_commit_free(commit);
	git_buf_free(&buf);
}

void test_diff_format_email__simple(void)
{
	git_diff_format_email_options opts = GIT_DIFF_FORMAT_EMAIL_OPTIONS_INIT;
	const char *email =
	assert_email_match(
		email, "9264b96c6d104d0e07ae33d3007b6a48246c6f92", &opts);
 	git_diff_format_email_options opts = GIT_DIFF_FORMAT_EMAIL_OPTIONS_INIT;
	const char *email =

	cl_assert_equal_s(email, git_buf_cstr(&buf));
	const char *email =
	assert_email_match(
		email, "9264b96c6d104d0e07ae33d3007b6a48246c6f92", &opts);
	const char *email =
	assert_email_match(
		email, "7ade76dd34bba4733cf9878079f9fd4a456a9189", &opts);
	const char *email =
	assert_email_match(
		email, "6e05acc5a5dab507d91a0a0cc0fb05a3dd98892d", &opts);
	assert_email_match(
		email, "9264b96c6d104d0e07ae33d3007b6a48246c6f92", &opts);
	/* TODO: Actually 0 bytes here should be 5!. Seems like we don't load the new content for binary files? */
	assert_email_match(
		email, "8d7523f6fcb2404257889abe0d96f093d9f524f9", &opts);